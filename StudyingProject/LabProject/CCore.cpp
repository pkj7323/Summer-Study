// Date: 2021/09/30
#include "pch.h"
#include "CCore.h"
#include "CObject.h"

CObject obj;

CCore::CCore() :
	m_hdc{}, m_backdc{}, m_hwnd{}, m_bitmap{}, m_ptResolution{}
{
}
CCore::~CCore()
{
}


int CCore::Init(HWND hWnd, POINT pt)
{
	m_hwnd = hWnd;
	m_ptResolution = pt;
	RECT rc = { 0, 0, m_ptResolution.x, m_ptResolution.y };
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, true);
	m_ptResolution.x = rc.right - rc.left;
	m_ptResolution.y = rc.bottom - rc.top;
	SetWindowPos(m_hwnd, nullptr, 100, 100, rc.right - rc.left, rc.bottom - rc.top, 0);

	m_hdc = GetDC(m_hwnd);
	obj.setPos(Vec2((float)(m_ptResolution.x / 2.f), (float)(m_ptResolution.y / 2.f)));
	obj.setScale(Vec2(100, 100));
	return S_OK;
}

void CCore::Progress()
{
	update();
	render();

}

void CCore::update()
{
	Vec2 vPos = obj.GetPos();
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		vPos.x -= 10;
		
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		vPos.x += 10;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		vPos.y -= 10;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		vPos.y += 10;
	}
	obj.setPos(vPos);
}

void CCore::render()
{
	Rectangle(m_hdc
		, obj.GetPos().x - obj.GetSacle().x / 2
		, obj.GetPos().y - obj.GetSacle().y / 2
		, obj.GetPos().x + obj.GetSacle().x / 2
		, obj.GetPos().y + obj.GetSacle().y / 2);
}




