#include "pch.h"
#include "CObject.h"

#include "KeyMgr.h"
#include "TimeMgr.h"

CObject::CObject() :
	vPos{}, vScale{10.f,10.f}
{
}

CObject::~CObject()
{
}

void CObject::Update()
{
	
}

void CObject::Render(HDC hDC)
{
	Rectangle(hDC
		, static_cast<int>(vPos.x - vScale.x / 2.f)
		, static_cast<int>(vPos.y - vScale.y / 2.f)
		, static_cast<int>(vPos.x + vScale.x / 2.f)
		, static_cast<int>(vPos.y + vScale.y / 2.f));
}
