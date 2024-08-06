#include "pch.h"
#include "SceneMgr.h"
#include "StartScene.h"
#include "CScene.h"

SceneMgr::SceneMgr() : m_CurrScene(nullptr), arrScene{}
{
}
SceneMgr::~SceneMgr()
{
}

void SceneMgr::Init()
{
	arrScene[static_cast<UINT>(SCENE_TYPE::START)] = new StartScene;
	arrScene[static_cast<UINT>(SCENE_TYPE::START)]->SetName(L"StartScene");
	
	m_CurrScene = arrScene[static_cast<UINT>(SCENE_TYPE::START)];
	m_CurrScene->Enter();

}

void SceneMgr::Update()
{
	m_CurrScene->Update();
}

void SceneMgr::Render(HDC hDC)
{
	m_CurrScene->Render(hDC);
}
