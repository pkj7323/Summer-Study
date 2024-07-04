#include "pch.h"
#include "TimeMgr.h"
#include "CCore.h"

TimeMgr::TimeMgr() 
	: dDT(0.)
	, dAcc(0.)
	, iFPS(0.)
	, iCallCount(0.)
	, curCount{0}
	, prevCount{0}
	, preQuency{0}
{
}
TimeMgr::~TimeMgr()
{
}

void TimeMgr::Init()
{
	QueryPerformanceCounter(&prevCount);
	QueryPerformanceFrequency(&preQuency);
}

void TimeMgr::Update()
{
	QueryPerformanceCounter(&curCount);
	dDT = (double)(curCount.QuadPart - prevCount.QuadPart) / (double)preQuency.QuadPart;
	prevCount = curCount;
#ifdef DEBUG
	if(dDT>(1./60.f))
		dDT = 1. / 60.f;
#endif // DEBUG

	
	
}

void TimeMgr::Render()
{
	++iCallCount;
	dAcc += dDT;

	if (dAcc >= 1.)
	{
		iFPS = iCallCount;
		iCallCount = 0;
		dAcc = 0.;
		wchar_t szFPS[64] = L"";
		swprintf_s(szFPS, L"FPS : %d DT: %f\n", iFPS, dDT);

		SetWindowText(CCore::Instance()->GetHwnd(), szFPS);
	}
}


