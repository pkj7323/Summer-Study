#include "pch.h"
#include "CScene.h"
#include "CObject.h"
#include "Missile.h"
CScene::CScene()
{
}

CScene::~CScene()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (size_t j = 0; j < m_vecObj[i].size(); j++)
		{
			delete m_vecObj[i][j];
		}
	}
}



void CScene::DeleteObject()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (size_t j = 0; j < m_vecObj[i].size(); j++)
		{
			if (m_vecObj[i][j]->GetIsDead())
			{
				delete m_vecObj[i][j];
				m_vecObj[i][j] = m_vecObj[i].back();
				m_vecObj[i].pop_back();
			}
		}
	}

}
void CScene::Update()
{
	CScene::DeleteObject();
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (size_t j = 0; j < m_vecObj[i].size(); j++)
		{
			m_vecObj[i][j]->Update();
		}
	}
	
}

void CScene::Render(HDC hDC)
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (size_t j = 0; j < m_vecObj[i].size(); j++)
		{
			m_vecObj[i][j]->Render(hDC);
		}
	}
}

void CScene::Shoot(Vec2 pos, float damage, float speed, float theta)
{
	
	auto pMissile = AddObject<Missile>(GROUP_TYPE::MISSILE);
	pMissile->Shoot(pos, damage, speed, theta);
}




