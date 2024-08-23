#pragma once
#include "CComponent.h"
class CTexture;
class CRenderer : public CComponent
{
public:
	CRenderer();
	~CRenderer();

	void Init() override;
	void Update() override;
	void Render(HDC hDC) override;
	void Load(const wstring& _strPath);

	void SetOffsetPos(const Vec2& _vOffsetPos) { m_vOffsetPos = _vOffsetPos; }
	void SetOffsetSize(const Vec2& _vOffsetSize) { m_vOffsetSize = _vOffsetSize; }
private:
	CTexture*	m_pTexture;
	Vec2		m_vSize;
	Vec2		m_vPivot;
	Vec2		m_vOffsetPos;
	Vec2		m_vOffsetSize;
};

