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
	if (KeyMgr::Instance()->GetKeyState(KEY::W) == KEY_STATE::HOLD)
	{
		vPos.y -= 200 * fDT;
	}
	if (KeyMgr::Instance()->GetKeyState(KEY::S) == KEY_STATE::HOLD)
	{
		vPos.y += 200 * fDT;
	}
	if (KeyMgr::Instance()->GetKeyState(KEY::D) == KEY_STATE::HOLD)
	{
		vPos.x += 200 * fDT;
	}
	if (KeyMgr::Instance()->GetKeyState(KEY::A) == KEY_STATE::HOLD)
	{
		vPos.x -= 200 * fDT;
	}

	if (KeyMgr::Instance()->GetKeyState(KEY::DOWN) == KEY_STATE::TAP)
	{
		SceneMgr::Instance()->GetCurrScene()->Shoot(GetPos(), 1, NULL, Vec2_Down);
	}
	if (KeyMgr::Instance()->GetKeyState(KEY::RIGHT) == KEY_STATE::TAP)
	{
		SceneMgr::Instance()->GetCurrScene()->Shoot(GetPos(), 1, NULL, Vec2_Right);
	}
	if (KeyMgr::Instance()->GetKeyState(KEY::LEFT) == KEY_STATE::TAP)
	{
		SceneMgr::Instance()->GetCurrScene()->Shoot(GetPos(), 1, NULL, Vec2_Left);
	}
	if (KeyMgr::Instance()->GetKeyState(KEY::UP) == KEY_STATE::TAP)
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


