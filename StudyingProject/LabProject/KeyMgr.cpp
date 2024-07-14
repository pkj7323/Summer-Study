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
	'Q',
	'W',
	'E',
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
	'R',
	'Z',
	'X',
	'C',
	'V',
	'B',
	'N',
	'M',

	VK_LSHIFT,
	VK_END,

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
}
