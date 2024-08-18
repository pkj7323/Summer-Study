#pragma once
#include "CObject.h"
#include "Missile.h"
class Player : public CObject
{
public:
	Player();
	~Player();

	void Update() override;
	void Render(HDC hDC) override;
private:
	float	m_ShootDir;
};

