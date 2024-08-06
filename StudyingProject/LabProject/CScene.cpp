#include "pch.h"
#include "CScene.h"

#include "CObject.h"
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



void CScene::Update()
{
	for (UINT i = 0; i < (UINT)GROUP_TYPE::END; ++i)
	{
		for (size_t j = 0; j < m_vecObj[i].size(); j++)
		{
			m_vecObj[i][j]->Update();
		}
	}
	CScene::DeleteObject(GROUP_TYPE::ENEMY);
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

void CScene::DeleteObject(GROUP_TYPE eGroupType)
{
	for (size_t i = 0; i < m_vecObj[static_cast<UINT>(eGroupType)].size(); i++)
	{
		if (m_vecObj[static_cast<UINT>(eGroupType)][i]->GetIsDead())
		{
			delete m_vecObj[static_cast<UINT>(eGroupType)][i];
			m_vecObj[static_cast<UINT>(eGroupType)][i] = m_vecObj[static_cast<UINT>(eGroupType)].back();
			m_vecObj[static_cast<UINT>(eGroupType)].pop_back();
		}
	}
}


