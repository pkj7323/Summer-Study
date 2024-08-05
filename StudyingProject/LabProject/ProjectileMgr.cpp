#include "pch.h"
#include "ProjectileMgr.h"
#include "Missile.h"

ProjectileMgr::ProjectileMgr()
{
}
ProjectileMgr::~ProjectileMgr()
{
	Release();
}

void ProjectileMgr::Init()
{
}

void ProjectileMgr::Update()
{
	for (size_t i = 0; i < m_vMissile.size(); ++i)
	{
		m_vMissile[i]->Update();
		if (m_vMissile[i]->GetIsDead())
		{
			delete m_vMissile[i];
			m_vMissile.erase(m_vMissile.begin() + i);
		}
	}
}

void ProjectileMgr::Render(HDC hDC)
{
	for (size_t i = 0; i < m_vMissile.size(); ++i)
	{
		m_vMissile[i]->Render(hDC);
	}
}

void ProjectileMgr::Release()
{
	for (size_t i = 0; i < m_vMissile.size(); ++i)
	{
		delete m_vMissile[i];
	}
	m_vMissile.clear();
}

void ProjectileMgr::Shoot(Vec2 pos, float damage, float speed, Vec2 Dir, GROUP_TYPE Group_Type)
{
	Missile* pMissile = new Missile;
	pMissile->SetGroupType(Group_Type);
	pMissile->Shoot(pos, damage, speed, Dir);
	m_vMissile.push_back(pMissile);
}
