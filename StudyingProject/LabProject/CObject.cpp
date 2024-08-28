#include "pch.h"
#include "CObject.h"
#include "CComponent.h"
#include "KeyMgr.h"
#include "TimeMgr.h"

CObject::CObject() :
	vPos{}, vScale{ 10.f,10.f }, bDead{ false }, bDamage{ 0.f }, eGroupType{ GROUP_TYPE::END }
{
	m_vecComponents.resize(static_cast<UINT>(ComponentType::END));
}

CObject::~CObject()
{
	for (auto pComponents : m_vecComponents)
	{
		if (pComponents == nullptr)
		{
			continue;
		}
		delete pComponents;
	}
	m_vecComponents.clear();
}



void CObject::Update()
{
	for (auto pComponents : m_vecComponents)
	{
		if (pComponents == nullptr)
		{
			continue;
		}
		pComponents->Update();
	}
}

void CObject::Render(HDC hDC)
{
	
	for (auto pComponents : m_vecComponents)
	{
		if (pComponents==nullptr)
		{
			continue;
		}
		pComponents->Render(hDC);
	}
//사각형 콜리젼 영역 같은거 u know?
	Rectangle(hDC
		, static_cast<int>(vPos.x - vScale.x / 2.f)
		, static_cast<int>(vPos.y - vScale.y / 2.f)
		, static_cast<int>(vPos.x + vScale.x / 2.f)
		, static_cast<int>(vPos.y + vScale.y / 2.f));
}
