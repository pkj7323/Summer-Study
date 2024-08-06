#include "pch.h"
#include "Missile.h"
#include "TimeMgr.h"
#include "CCore.h"
Missile::Missile() :
	m_speed{ 500.f }, m_dir{ Vec2_Zero }, m_isFired{ false }
{
	SetDamage(0.f);
	SetIsDead(false);
}

Missile::~Missile()
{
}

void Missile::Update()
{
	if (GetIsDead())
		return;
	if (!m_isFired)
		return;
	Vec2 curPos = GetPos();
	curPos.x += m_speed * m_dir.x * fDT;
	curPos.y += m_speed * m_dir.y * fDT;

	SetPos(curPos);
	if (fabs(GetPos().x - CCore::Instance()->GetResolution().x) > static_cast<float>(CCore::Instance()->GetResolution().x + GetScale().x)
		|| fabs(GetPos().y - CCore::Instance()->GetResolution().y) > static_cast<float>(CCore::Instance()->GetResolution().y) + GetScale().x)
	{
		SetIsDead(true);
	}
}

void Missile::Render(HDC hDC)
{
	if (GetIsDead())
		return;
	if (!m_isFired)
		return;
	HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 255));
	HBRUSH hOldBrush = static_cast<HBRUSH>(SelectObject(hDC, hBrush));

	if (m_dir.y == -1 || m_dir.y == 1)
	{
		SetScale(Vec2(10.f, 20.f));
		Rectangle(hDC
			, static_cast<int>(GetPos().x - GetScale().x / 2.f)
			, static_cast<int>(GetPos().y - GetScale().y / 2.f)
			, static_cast<int>(GetPos().x + GetScale().x / 2.f)
			, static_cast<int>(GetPos().y + GetScale().y / 2.f));
	}
	if (m_dir.x == -1 || m_dir.x == 1)
	{
		SetScale(Vec2(20.f, 10.f));
		Rectangle(hDC
			, static_cast<int>(GetPos().x - GetScale().x / 2.f)
			, static_cast<int>(GetPos().y - GetScale().y / 2.f)
			, static_cast<int>(GetPos().x + GetScale().x / 2.f)
			, static_cast<int>(GetPos().y + GetScale().y / 2.f));
	}
	DeleteObject(SelectObject(hDC, hOldBrush)); 

}

void Missile::Shoot(Vec2 pos, float damage, float speed, Vec2 Dir)
{
	this->SetPos(pos);
	SetDamage(damage);
	if (speed > 0)
	{
		this->m_speed = speed;
	}
	m_dir = Dir;
	m_isFired = true;
}
