#pragma once

class CScene;
class SceneMgr
{
	SINGLE(SceneMgr);
public:
	void Init();
	void Update();
	void Render(HDC hDC);
private:
	CScene* arrScene[static_cast<UINT>(SCENE_TYPE::END)];
};

