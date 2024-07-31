#include "pch.h"
#include "Monster.h"

#include "TimeMgr.h"
Monster::Monster()
	:speed{ 100 }, maxDis{ 50 }, dir{ 1 }, centerPos{Vec2(0,0)}
{
}

Monster::~Monster()
{
}

void Monster::Update()
{
	Vec2 curPos = GetPos();
	curPos.x += speed * fDT * dir;

	float dist = abs(centerPos.x - curPos.x) - maxDis;
	if (0.f < dist)
	{
		dir *= -1;
		curPos.x += dist * dir;
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


