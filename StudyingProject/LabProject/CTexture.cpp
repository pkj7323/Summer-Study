#include "pch.h"
#include "CTexture.h"

CTexture::CTexture() : CResource(ResourceType::TEXTURE)
{
}

CTexture::~CTexture()
{
}

HRESULT CTexture::Load(const wstring& _path)
{
	
	m_pImage = Gdiplus::Image::FromFile(_path.c_str());
	m_iWidth = m_pImage->GetWidth();
	m_iHeight = m_pImage->GetHeight();

	if (m_pImage->GetLastStatus() == Gdiplus::Status::Ok)
	{
		return S_OK;
	}
	else
	{
		return E_FAIL;
	}
    
}

void CTexture::Render(HDC _hdc, INT x,INT y,INT width,INT height)
{
	
	Gdiplus::Graphics graphics(_hdc);
	graphics.DrawImage(m_pImage, x, y, width, height);
	
}
