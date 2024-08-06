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

	void SetDamage(float damage) { m_damage = damage; }
	float GetDamage() { return m_damage; }

	

	void SetGroupType(GROUP_TYPE groupType) { m_groupType = groupType; }
	GROUP_TYPE GetGroupType() { return m_groupType; }
private:
	float		m_damage;
	float		m_speed;
	Vec2		m_dir;
	bool		m_isFired;
	
	GROUP_TYPE	m_groupType;
};

