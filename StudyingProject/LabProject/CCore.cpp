// Date: 2021/09/30
#include "pch.h"
//������ ���� include�ؾ���

#include "TimeMgr.h"
#include "KeyMgr.h"
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

	//���� ���۸� �뵵�� ��Ʈ�ʰ� dc�� �����.
	m_hbitmap	= CreateCompatibleBitmap(m_hdc, m_ptResolution.x, m_ptResolution.y);
	m_mdc		= CreateCompatibleDC(m_hdc);
	

	HBITMAP oldBitmap = (HBITMAP)SelectObject(m_mdc, m_hbitmap); //���� �ʿ���� ��Ʈ���� �����Ͽ� �ٷ� �����Ѵ�.
	DeleteObject(oldBitmap);


	obj.setPos(Vec2(static_cast<float>(m_ptResolution.x / 2.f), static_cast<float>(m_ptResolution.y / 2.f)));
	obj.setScale(Vec2(100, 100));


	//Manger �ʱ�ȭ
	TimeMgr::Instance()->Init();
	KeyMgr::Instance()->Init();


	return S_OK;
}

void CCore::Progress()
{
	update();
	render();
	//progress�� ������Ʈ�� ������ ���ܵδ� ���� ����.
}

void CCore::update()
{
	TimeMgr::Instance()->Update();
	KeyMgr::Instance()->Update();


	Vec2 vPos = obj.GetPos();
	if (KeyMgr::Instance()->GetKeyState(KEY::LEFT) == KEY_STATE::HOLD)
	{
		vPos.x -= 300 * fDT;
	}
	if (KeyMgr::Instance()->GetKeyState(KEY::RIGHT) == KEY_STATE::HOLD)
	{
		vPos.x += 300 * fDT;
	}
	if (KeyMgr::Instance()->GetKeyState(KEY::UP) == KEY_STATE::HOLD)
	{
		vPos.y -= 300 * fDT;
	}
	if (KeyMgr::Instance()->GetKeyState(KEY::DOWN) == KEY_STATE::HOLD)
	{
		vPos.y += 300 * fDT;
	}
	obj.setPos(vPos);
	
}

void CCore::render()
{
	TimeMgr::Instance()->Render();
	Rectangle(m_mdc, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);
	Rectangle(m_mdc
		, static_cast<int>(obj.GetPos().x - obj.GetSacle().x / 2)
		, static_cast<int>(obj.GetPos().y - obj.GetSacle().y / 2)
		, static_cast<int>(obj.GetPos().x + obj.GetSacle().x / 2)
		, static_cast<int>(obj.GetPos().y + obj.GetSacle().y / 2));

	BitBlt(m_hdc, 0, 0, m_ptResolution.x, m_ptResolution.y, m_mdc, 0, 0, SRCCOPY);
	//������ ����� ��Ÿ������ ��� �� �̿ܿ� ������ ����� �߻����� ���� ���ִ�.
	//3d�� ���� �ʹ� �������Ƿ� gpu���
}




