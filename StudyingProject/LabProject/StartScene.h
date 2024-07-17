#pragma once
#include "CScene.h"
class StartScene : public CScene
{
public:
	StartScene();
	~StartScene();

	void Enter();
	void Exit();
	void Update() override;
	void Render(HDC hDC) override;
};

