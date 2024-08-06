#pragma once
#include "CObject.h"
class Monster :	public CObject
{
public:
	Monster();
	~Monster();

	virtual void Update() override;
	virtual void Render(HDC hDC) override;

	float GetSpeed() { return speed; }
	void SetSpeed(float speed) { this->speed = speed; }

	float GetMaxDis() { return maxDis; }
	void SetMaxDis(float maxDis) { this->maxDis = maxDis; }

	int GetDir() { return dir; }
	void SetDir(int dir) { this->dir = dir; }

	Vec2 GetCenterPos() { return centerPos; }
	void SetCenterPos(Vec2 centerPos) { this->centerPos = centerPos; }

	void SetHp(float hp) { this->hp = hp; }
	float GetHp() { return hp; }
private:
	float	speed;
	float	maxDis;
	int		dir;
	Vec2	centerPos;
	float	hp;
	
};

