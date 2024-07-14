// Date: 2021/09/30
#include "pch.h"
//무조건 먼저 include해야함

#include "TimeMgr.h"
#include "CCore.h"
#include "CObject.h"


CObject obj;

CCore::CCore() :
	m_hdc{}, m_mdc{}, m_hwnd{}, m_hbitmap{}, m_ptResolution{}
{
}
CCore::~CCore()
{
	ReleaseDC(m_hwnd, m_hdc);

	DeleteDC(m_mdc);
	DeleteObject(m_hbitmap);
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

	//이중 버퍼링 용도의 비트맵과 dc를 만든다.
	m_hbitmap	= CreateCompatibleBitmap(m_hdc, m_ptResolution.x, m_ptResolution.y);
	m_mdc		= CreateCompatibleDC(m_hdc);
	

	HBITMAP oldBitmap = (HBITMAP)SelectObject(m_mdc, m_hbitmap);
	DeleteObject(oldBitmap);


	obj.setPos(Vec2((float)(m_ptResolution.x / 2.f), (float)(m_ptResolution.y / 2.f)));
	obj.setScale(Vec2(100, 100));

	TimeMgr::Instance()->Init();


	return S_OK;
}

void CCore::Progress()
{
	TimeMgr::Instance()->Update();
	TimeMgr::Instance()->Render();
	update();
	render();

}

void CCore::update()
{
	Vec2 vPos = obj.GetPos();
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		vPos.x -= 300 * fDT;
		
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		vPos.x += 300 * fDT;
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		vPos.y -= 300 * fDT;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		vPos.y += 300 * fDT;
	}
	obj.setPos(vPos);
	
}

void CCore::render()
{
	Rectangle(m_mdc, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);
	Rectangle(m_mdc
		, static_cast<int>(obj.GetPos().x - obj.GetSacle().x / 2)
		, static_cast<int>(obj.GetPos().y - obj.GetSacle().y / 2)
		, static_cast<int>(obj.GetPos().x + obj.GetSacle().x / 2)
		, static_cast<int>(obj.GetPos().y + obj.GetSacle().y / 2));

	BitBlt(m_hdc, 0, 0, m_ptResolution.x, m_ptResolution.y, m_mdc, 0, 0, SRCCOPY);
	//프레임 드랍이 나타나지만 적어도 이 이외에 프레임 드랍이 발생하지 않을 수있다.
	//3d로 가면 너무 많아지므로 gpu사용
}




