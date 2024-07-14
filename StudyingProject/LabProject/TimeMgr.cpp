#include "pch.h"
#include "TimeMgr.h"
#include "CCore.h"

TimeMgr::TimeMgr() 
	: dDT(0.)
	, dAcc(0.)
	, iFPS(0)
	, iCallCount(0)
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
	QueryPerformanceCounter(&prevCount);//초기화 할때의 클럭의 성능 카운터를 센다.
	QueryPerformanceFrequency(&preQuency);//현재 클럭의 1초당 진동수를 가져온다.
}

void TimeMgr::Update()
{
	QueryPerformanceCounter(&curCount);//일정 지점 안에서 몇 번 진동 하였는가를 나타내는 함수
	dDT = (double)(curCount.QuadPart - prevCount.QuadPart) / (double)preQuency.QuadPart;
	prevCount = curCount;
	//정확한 이해를 해야하겠음 약간 이해안됨 
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
		swprintf_s(szFPS, L"FPS : %d DeltaTime: %f\n", iFPS, dDT);

		SetWindowText(CCore::Instance()->GetHwnd(), szFPS);
	}
}


