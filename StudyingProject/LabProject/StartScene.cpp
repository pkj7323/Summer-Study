#include "pch.h"
#include "StartScene.h"
#include "CObject.h"
#include "Player.h"

StartScene::StartScene()
{
}

StartScene::~StartScene()
{
}

void StartScene::Enter()
{
	//object Ãß°¡
	CObject* pObj = new Player;
	pObj->SetPos(Vec2(640, 348));
	pObj->SetScale(Vec2(100, 100));
	AddObject(pObj, GROUP_TYPE::PLAYER);

	CObject* Obj = new CObject;
	Obj->SetPos(Vec2(640, 348));
	Obj->SetScale(Vec2(100, 100));
	AddObject(Obj, GROUP_TYPE::DEFAULT);

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
