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

	vector<Missile*>& GetMissiles() { return m_vMissile; }
private:
	vector<Missile*> m_vMissile;
};

