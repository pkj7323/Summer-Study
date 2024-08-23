#include "pch.h"
#include "CComponent.h"



CComponent::CComponent(ComponentType _ComponentType) :
	m_eComponentType(_ComponentType), m_pOwner(nullptr)
{
}

CComponent::~CComponent()
{
}

void CComponent::Init()
{
}

void CComponent::Update()
{
}

void CComponent::Render(HDC hDC)
{
}
