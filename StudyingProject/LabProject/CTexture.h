#pragma once
#include "CResource.h"
class CTexture : public CResource
{
public:
	CTexture();
	~CTexture();

	virtual HRESULT Load(const wstring& _path) override;

	void Render(HDC _hdc, INT x, INT y, INT width, INT height);

	


private:
	Gdiplus::Image* m_pImage;

	HDC				m_hDC;
	HBITMAP			m_hBit;
	UINT			m_iWidth;
	UINT			m_iHeight;
};

