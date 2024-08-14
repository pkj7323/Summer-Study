#pragma once
#include "CObject.h"
class Missile : public CObject
{
public:
	Missile();
	~Missile();
	virtual void Update() override;
	virtual void Render(HDC hDC) override;

	void Shoot(Vec2 pos, float damage, float speed, Vec2 Dir);

private:
	float		m_theta;
	float		m_speed;
	Vec2		m_dir;
	bool		m_isFired;
};

