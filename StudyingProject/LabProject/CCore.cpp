// Date: 2021/09/30
#include "pch.h"
//������ ���� include�ؾ���

#include "TimeMgr.h"
#include "KeyMgr.h"
#include "CCore.h"
#include "CObject.h"
#include "SceneMgr.h"
#include "ProjectileMgr.h"




CCore::CCore() :
	m_hdc{}, m_mdc{}, m_hwnd{}, m_hbitmap{}, m_ptResolution{}
{
}
CCore::~CCore()
{
	ProjectileMgr::Instance()->Release();
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
	SetWindowPos(m_hwnd, nullptr, 100, 100, rc.right - rc.left, rc.bottom - rc.top, 0);



	m_hdc = GetDC(m_hwnd);

	//���� ���۸� �뵵�� ��Ʈ�ʰ� dc�� �����.
	m_hbitmap	= CreateCompatibleBitmap(m_hdc, m_ptResolution.x, m_ptResolution.y);
	m_mdc		= CreateCompatibleDC(m_hdc);
	

	HBITMAP oldBitmap = (HBITMAP)SelectObject(m_mdc, m_hbitmap); //���� �ʿ���� ��Ʈ���� �����Ͽ� �ٷ� �����Ѵ�.
	DeleteObject(oldBitmap);


	

	//Manger �ʱ�ȭ
	TimeMgr::Instance()->Init();
	KeyMgr::Instance()->Init();
	SceneMgr::Instance()->Init();


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
	ProjectileMgr::Instance()->Update();//������Ÿ�� �Ŵ����� ������Ʈ�� ������ġ�� ��� �ؾ��ұ�?
	SceneMgr::Instance()->Update();

	
	
}

void CCore::render()
{
	
	Rectangle(m_mdc, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);
	ProjectileMgr::Instance()->Render(m_mdc);
	SceneMgr::Instance()->Render(m_mdc);
	

	BitBlt(m_hdc, 0, 0, m_ptResolution.x, m_ptResolution.y, m_mdc, 0, 0, SRCCOPY);
	//������ ����� ��Ÿ������ ��� �� �̿ܿ� ������ ����� �߻����� ���� ���ִ�.
	//3d�� ���� �ʹ� �������Ƿ� gpu���
	TimeMgr::Instance()->Render();
}




