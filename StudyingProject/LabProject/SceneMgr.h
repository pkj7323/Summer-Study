#pragma once

class CScene;
class SceneMgr
{
	SINGLE(SceneMgr);
public:
	void Init();
	void Update();
	void Render(HDC hDC);

	CScene* GetCurrScene() { return m_CurrScene; }
private:
	CScene* arrScene[static_cast<UINT>(SCENE_TYPE::END)];
	CScene* m_CurrScene = nullptr;
};

