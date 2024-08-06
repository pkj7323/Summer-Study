#pragma once
class Missile;
class ProjectileMgr
{
	SINGLE(ProjectileMgr);
public:
	void Init();
	void Update();
	void Render(HDC hDC);
	void Release();
	void Shoot(Vec2 pos, float damage, float speed, Vec2 Dir, GROUP_TYPE Group_Type);

	//프로젝타일 매니져를 써야 할지 씬 부모 객체에 만들어 놓을지는 생각을 해봐야겟음
	vector<Missile*>& GetMissiles() { return m_vMissile; }
private:
	vector<Missile*> m_vMissile;
};

