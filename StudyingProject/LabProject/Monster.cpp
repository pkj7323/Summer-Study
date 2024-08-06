#include "pch.h"
#include "Monster.h"
#include "Missile.h"
#include "TimeMgr.h"
#include "SceneMgr.h"
#include "CScene.h"
Monster::Monster()
	:speed{ 100 }, maxDis{ 50 }, dir{ 1 }, centerPos{ Vec2(0,0) }, hp{ 10.f }
{
}

Monster::~Monster()
{
}

void Monster::Update()
{
	if (hp <= 0)
		SetIsDead(true);
	if (GetIsDead())
		return;
	
	Vec2 curPos = GetPos();
	curPos.x += speed * fDT * dir;

	float dist = abs(centerPos.x - curPos.x) - maxDis;
	if (0.f < dist)
	{
		dir *= -1;
		curPos.x += dist * dir;
	}
	
	auto pMissiles = SceneMgr::Instance()->GetCurrScene()->GetObjectArr(GROUP_TYPE::MISSILE);
	for (size_t i = 0; i < pMissiles.size(); ++i)
	{
		if (pMissiles[i]->GetGroupType() == GROUP_TYPE::MISSILE)
		{
			if (((GetPos().x - GetScale().x / 2.f) < pMissiles[i]->GetPos().x 
				&& (GetPos().x + GetScale().x / 2.f) > pMissiles[i]->GetPos().x)
				&& ((GetPos().y - GetScale().y / 2.f) < pMissiles[i]->GetPos().y 
					&& (GetPos().y + GetScale().y / 2.f) > pMissiles[i]->GetPos().y))
			{
				hp -= pMissiles[i]->GetDamage();
				pMissiles[i]->SetIsDead(true);
			}
		}

	}

	SetPos(curPos);
}

void Monster::Render(HDC hDC)
{
	HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH hOldBrush = static_cast<HBRUSH>(SelectObject(hDC, hBrush));

	Rectangle(hDC
		, static_cast<int>(GetPos().x - GetScale().x / 2.f)
		, static_cast<int>(GetPos().y - GetScale().y / 2.f)
		, static_cast<int>(GetPos().x + GetScale().x / 2.f)
		, static_cast<int>(GetPos().y + GetScale().y / 2.f));

	DeleteObject(SelectObject(hDC, hOldBrush));
}


