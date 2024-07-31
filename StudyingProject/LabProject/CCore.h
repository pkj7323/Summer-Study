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
//�̱��� : �ϳ��� �ν��Ͻ��� ����� ���� ���
//�ϳ��� ��ü�� ����� ���� ���

//Ŭ���� - �����ڿ� �Ҹ��ڸ� private�� ���� �ܺο��� ��ü�� �������� ���ϰ� �Ѵ�.
//GetInstance() �Լ��� ���� ��ü�� �����ϰ� ��ȯ�Ѵ�.
//��ü�� ���������.
//����Լ� ��������� ������ �� �־�? -> ��ü�� ����.
//��� ȣ���� �� �ִ�.? -> static�̸� ������ ���� ��� �Լ��� ���� ��������θ� �����Ѵ�.

//static�Լ��� ������ ���α׷� ���۽� �޸𸮿� �ö󰡰� ����� �޸𸮿��� �����ȴ�.
