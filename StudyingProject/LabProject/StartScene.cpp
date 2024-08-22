#include "pch.h"
#include "StartScene.h"
#include "CObject.h"
#include "Player.h"
#include "Monster.h"
#include "CCore.h"
#include "CTexture.h"
#include "PathMgr.h"
StartScene::StartScene()
{
}

StartScene::~StartScene()
{
}

void StartScene::Enter()
{
	//object 추가
	auto pObj = AddObject<Player>(GROUP_TYPE::PLAYER);
	pObj->SetPos(Vec2(640, 348));
	pObj->SetScale(Vec2(100, 100));
	
	//몬스터 추가
	int monCount = 5;
	float moveDist = 25.f;
	float objScale = 50.f;
	Vec2 resolution = CCore::Instance()->GetResolution();
	float term = (resolution.x - ((moveDist + objScale / 2.f) * 2.f)) / (float)(monCount - 1);

	for (size_t i = 0; i < monCount; i++)
	{
		auto monster = AddObject<Monster>(GROUP_TYPE::ENEMY);
		monster->SetCenterPos(Vec2((moveDist + objScale / 2.f) + (float)i * term, 100.f));
		monster->SetPos(Vec2(monster->GetCenterPos()));
		monster->SetMaxDis(moveDist);
		monster->SetScale(Vec2(objScale, objScale));
	}
}

void StartScene::Exit()
{
}

void StartScene::Update()
{
	
}

void StartScene::Render(HDC hDC)
{
}
