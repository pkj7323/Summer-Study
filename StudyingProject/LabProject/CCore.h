#pragma once
class CCore
{
	SINGLE(CCore);
public:
	
	int Init(HWND, POINT);
	void Progress();
	HWND GetHwnd() { return m_hwnd; }
	POINT GetResolution() { return m_ptResolution; }
private:
	void render();
	void update();
private:
	HDC		m_hdc;
	HDC		m_mdc;
	HWND	m_hwnd;
	HBITMAP	m_hbitmap;
	POINT	m_ptResolution;
};
//싱글톤 : 하나의 인스턴스를 만들기 위해 사용
//하나의 객체를 만들기 위해 사용

//클래스 - 생성자와 소멸자를 private로 만들어서 외부에서 객체를 생성하지 못하게 한다.
//GetInstance() 함수를 통해 객체를 생성하고 반환한다.
//객체를 만들수없다.
//멤버함수 멤버변수에 접근할 수 있어? -> 객체가 없다.
//멤버 호출할 수 있다.? -> static이면 가능해 정작 멤버 함수는 정적 멤버변수로만 접근한다.

//static함수와 변수는 프로그램 시작시 메모리에 올라가고 종료시 메모리에서 해제된다.
