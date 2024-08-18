#include "pch.h"
#include "Missile.h"
#include "TimeMgr.h"
#include "CCore.h"
Missile::Missile() :
	m_speed{ 500.f }, m_dir{ Vec2_Up }, m_isFired{ false }
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

	m_dir.Normalize();
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
	SetScale(Vec2(10.f, 10.f));
	Ellipse(hDC, static_cast<int>(GetPos().x - GetScale().x), static_cast<int>(GetPos().y - GetScale().y),
		static_cast<int>(GetPos().x + GetScale().x), static_cast<int>(GetPos().y + GetScale().y));
	DeleteObject(SelectObject(hDC, hOldBrush)); 

}

void Missile::Shoot(Vec2 pos, float damage, float speed, float theta)
{
	this->SetPos(pos);
	this->SetDamage(damage);
	if (speed > 0)
	{
		this->m_speed = speed;
	}
	m_dir.Rotate(theta);
	this->m_isFired = true;
}
