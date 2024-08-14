#include "pch.h"
#include "Player.h"

#include "KeyMgr.h"
#include "TimeMgr.h"
#include "MIssile.h"

#include "SceneMgr.h"
#include "CScene.h"
Player::Player()
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

	
	if (KEY_HOLD(KEY::DOWN))
	{
		if (KEY_TAP(KEY::RIGHT))
		{
			SceneMgr::Instance()->GetCurrScene()->Shoot(GetPos(), 1, NULL, Vec2(1.f, 1.f));
		}
		else if (KEY_TAP(KEY::LEFT))
		{
			SceneMgr::Instance()->GetCurrScene()->Shoot(GetPos(), 1, NULL, Vec2(-1.f, 1.f));
		}
		
	}
	if (KEY_HOLD(KEY::UP))
	{
		if (KEY_TAP(KEY::RIGHT))
		{
			SceneMgr::Instance()->GetCurrScene()->Shoot(GetPos(), 1, NULL, Vec2(1.f, -1.f));
		}
		else if (KEY_TAP(KEY::LEFT))
		{
			SceneMgr::Instance()->GetCurrScene()->Shoot(GetPos(), 1, NULL, Vec2(-1.f, -1.f));
		}
		
	}
	if (KEY_TAP(KEY::DOWN))
	{
		
		SceneMgr::Instance()->GetCurrScene()->Shoot(GetPos(), 1, NULL, Vec2_Down);
	}
	if (KEY_TAP(KEY::RIGHT) && KEY_HOLD(KEY::UP) == false && KEY_HOLD(KEY::DOWN) == false)
	{
		SceneMgr::Instance()->GetCurrScene()->Shoot(GetPos(), 1, NULL, Vec2_Right);
	}
	if (KEY_TAP(KEY::LEFT) && KEY_HOLD(KEY::UP) == false && KEY_HOLD(KEY::DOWN) == false)
	{
		SceneMgr::Instance()->GetCurrScene()->Shoot(GetPos(), 1, NULL, Vec2_Left);
	}
	if (KEY_TAP(KEY::UP))
	{
		SceneMgr::Instance()->GetCurrScene()->Shoot(GetPos(), 1, NULL, Vec2_Up);
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


