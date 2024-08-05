// Date: 2021/09/30
#include "pch.h"
//무조건 먼저 include해야함

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

	//이중 버퍼링 용도의 비트맵과 dc를 만든다.
	m_hbitmap	= CreateCompatibleBitmap(m_hdc, m_ptResolution.x, m_ptResolution.y);
	m_mdc		= CreateCompatibleDC(m_hdc);
	

	HBITMAP oldBitmap = (HBITMAP)SelectObject(m_mdc, m_hbitmap); //전의 필요없는 비트맵을 선택하여 바로 삭제한다.
	DeleteObject(oldBitmap);


	

	//Manger 초기화
	TimeMgr::Instance()->Init();
	KeyMgr::Instance()->Init();
	SceneMgr::Instance()->Init();


	return S_OK;
}

void CCore::Progress()
{
	update();
	render();
	//progress는 업데이트와 렌더만 남겨두는 것이 좋다.
}

void CCore::update()
{
	TimeMgr::Instance()->Update();
	KeyMgr::Instance()->Update();
	ProjectileMgr::Instance()->Update();//프로젝타일 매니져의 업데이트와 렌더위치를 어디에 해야할까?
	SceneMgr::Instance()->Update();

	
	
}

void CCore::render()
{
	
	Rectangle(m_mdc, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);
	ProjectileMgr::Instance()->Render(m_mdc);
	SceneMgr::Instance()->Render(m_mdc);
	

	BitBlt(m_hdc, 0, 0, m_ptResolution.x, m_ptResolution.y, m_mdc, 0, 0, SRCCOPY);
	//프레임 드랍이 나타나지만 적어도 이 이외에 프레임 드랍이 발생하지 않을 수있다.
	//3d로 가면 너무 많아지므로 gpu사용
	TimeMgr::Instance()->Render();
}




