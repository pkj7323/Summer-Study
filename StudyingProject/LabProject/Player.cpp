#include "pch.h"
#include "Player.h"

#include "KeyMgr.h"
#include "TimeMgr.h"
#include "MIssile.h"

#include "SceneMgr.h"
#include "CScene.h"
Player::Player() : m_ShootDir{ 90.f }
{
}
Player::~Player()
{
}
void Player::Update()
{
	Vec2 vPos = GetPos();
	if (KEY_HOLD(KEY::W))
	{
		vPos.y -= 200 * fDT;
	}
	if (KEY_HOLD(KEY::S))
	{
		vPos.y += 200 * fDT;
	}
	if (KEY_HOLD(KEY::D))
	{
		vPos.x += 200 * fDT;
	}
	if (KEY_HOLD(KEY::A))
	{
		vPos.x -= 200 * fDT;
	}

	if (KEY_HOLD(KEY::LEFT))
	{
		m_ShootDir -= 100.f * fDT;
	}
	if (KEY_HOLD(KEY::RIGHT))
	{
		m_ShootDir += 100.f * fDT;
	}
	
	
	if (KEY_TAP(KEY::SPACE))
	{
		SceneMgr::Instance()->GetCurrScene()->Shoot(vPos, 10.f, 500.f, m_ShootDir);
	}
	
	SetPos(vPos);
}

void Player::Render(HDC hDC)
{
	Rectangle(hDC
		, static_cast<int>(GetPos().x - GetScale().x / 2.f)
		, static_cast<int>(GetPos().y - GetScale().y / 2.f)
		, static_cast<int>(GetPos().x + GetScale().x / 2.f)
		, static_cast<int>(GetPos().y + GetScale().y / 2.f));

}


