#pragma once
#include "CScene.h"
class Monster;
class StartScene : public CScene
{
public:
	StartScene();
	~StartScene();

	void Enter();
	void Exit();
	void Update();
	void Render(HDC hDC);

	

};

