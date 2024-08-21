#pragma once
#include "CObject.h"
class Missile : public CObject
{
public:
	Missile();
	~Missile();
	virtual void Update() override;
	virtual void Render(HDC hDC) override;

	void Shoot(Vec2 pos, float damage, float speed, float theta);

	void SetDir(Vec2 dir) { 
		m_dir = dir; 
		m_dir.Normalize(); 
	}
	Vec2 GetDir() { return m_dir; }
private:
	float		m_speed;
	Vec2		m_dir;
	bool		m_isFired;
};

