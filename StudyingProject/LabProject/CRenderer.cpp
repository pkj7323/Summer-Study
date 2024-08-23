#include "pch.h"
#include "CRenderer.h"
#include "CTexture.h"
#include "CObject.h"

CRenderer::CRenderer() : CComponent(ComponentType::SPRITE)
{
	
}

CRenderer::~CRenderer()
{
	delete m_pTexture;
}

void CRenderer::Init()
{
	m_pTexture = new CTexture();
	auto owner = GetOwner();
	m_vPivot.x = owner->GetPos().x - owner->GetScale().x / 2.f;
	m_vPivot.y = owner->GetPos().y - owner->GetScale().y / 2.f;

	m_vSize = owner->GetScale();
}

void CRenderer::Update()
{
	auto owner = GetOwner();
	m_vPivot.x = owner->GetPos().x - owner->GetScale().x / 2.f;
	m_vPivot.y = owner->GetPos().y - owner->GetScale().y / 2.f;

	m_vSize = owner->GetScale();
}

void CRenderer::Render(HDC hDC)
{
	m_pTexture->Render(hDC
		, m_vPivot.x + m_vOffsetPos.x
		, m_vPivot.y + m_vOffsetPos.y
		, m_vSize.x + m_vOffsetSize.x
		, m_vSize.y + m_vOffsetSize.y);
}

void CRenderer::Load(const wstring& _strPath)
{
	m_pTexture->Load(_strPath);
}
