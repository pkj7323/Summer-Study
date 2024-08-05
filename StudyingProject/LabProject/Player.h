#pragma once
#include "CObject.h"
#include "Missile.h"
class Player : public CObject
{
public:
	virtual void Update() override;
	virtual void Render(HDC hDC) override;

};

