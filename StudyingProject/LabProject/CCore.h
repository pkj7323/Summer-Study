#pragma once
class CCore
{
	SINGLE(CCore);
public:
	
	int Init(HWND, POINT);
	void Progress();
	
private:
	void render();
	void update();
private:
	HDC m_hdc;
	HDC m_backdc;
	HWND m_hwnd;
	BITMAP m_bitmap;
	POINT m_ptResolution;
};
//�̱��� : �ϳ��� �ν��Ͻ��� ����� ���� ���
//�ϳ��� ��ü�� ����� ���� ���

//Ŭ���� - �����ڿ� �Ҹ��ڸ� private�� ���� �ܺο��� ��ü�� �������� ���ϰ� �Ѵ�.
//GetInstance() �Լ��� ���� ��ü�� �����ϰ� ��ȯ�Ѵ�.
//��ü�� ���������.
//����Լ� ��������� ������ �� �־�? -> ��ü�� ����.
//��� ȣ���� �� �ִ�.? -> static�̸� ������ ���� ��� �Լ��� ���� ��������θ� �����Ѵ�.

//static�Լ��� ������ ���α׷� ���۽� �޸𸮿� �ö󰡰� ����� �޸𸮿��� �����ȴ�.
