#include "pch.h"
#include "KeyMgr.h"

#include"CCore.h"


int arrVK[(int)KEY::LAST]{
	VK_LEFT,
	VK_RIGHT,
	VK_UP,
	VK_DOWN,
	VK_SPACE,
	VK_RETURN,
	VK_ESCAPE,
	VK_MENU,
	VK_LSHIFT,
	VK_END,
	'Q',
	'W',
	'E',
	'R',
	'T',
	'Y',
	'U',
	'I',
	'O',
	'P',
	'A',
	'S',
	'D',
	'F',
	'G',
	'H',
	'J',
	'K',
	'L',
	'Z',
	'X',
	'C',
	'V',
	'B',
	'N',
	'M',
	//LAST
};

KeyMgr::KeyMgr()
{
}

KeyMgr::~KeyMgr()
{
}

void KeyMgr::Init()
{
	for (int i = 0; i < (int)KEY::LAST; ++i)
	{
		vecKey.emplace_back(KeyInfo{ KEY_STATE::NONE,false });
	}
}

void KeyMgr::Update()
{
	//������ ��Ŀ�� ������ �ʿ��� �ٸ� â�� ��� ��â�� �������� ���� ���� ����
	HWND hWnd = GetFocus();
	
	//������ ��Ŀ�� ���϶� (���� â�� ����)
	if (hWnd != nullptr)
	{
		//��� Ű�� ���ؼ� Ű�� ���ȴ°� üũ
		for (size_t i = 0; i < static_cast<int>(KEY::LAST); ++i)
		{
			if (GetAsyncKeyState(arrVK[i]) & 0x8000) //0x8000<-�̰� �ϰ� Ű�� �������� ���ȴٴ� �ǹ� 
				//&==(AND)��Ʈ������
			{
				//���� �����ӿ� ������ Ű�ε�
				if (vecKey[i].prev)
				{
					//���� �����ӿ� ������ Ű
					vecKey[i].state = KEY_STATE::HOLD;
				}
				else
				{
					//���� �����ӿ� �������� ���� Ű
					vecKey[i].state = KEY_STATE::TAP;
				}
				vecKey[i].prev = true;
			}
			else
			{
				//���� �����ӿ� �������� ���� Ű
				if (vecKey[i].prev)
				{
					vecKey[i].state = KEY_STATE::AWAY;
				}
				else
				{
					vecKey[i].state = KEY_STATE::NONE;
				}
				vecKey[i].prev = false;
			}
		}
	}
	//�׷��� ���� ��
	else
	{
		//������ ��Ŀ���� ���� ��
		for (size_t i = 0; i < static_cast<int>(KEY::LAST); ++i)
		{
			
			vecKey[i].prev = false;
			if (KEY_STATE::TAP == vecKey[i].state
				||KEY_STATE::HOLD == vecKey[i].state)
			{
				vecKey[i].state = KEY_STATE::AWAY;
			}
			else if (KEY_STATE::AWAY == vecKey[i].state)
			{
				vecKey[i].state = KEY_STATE::NONE;
			}
		}
	}




}
