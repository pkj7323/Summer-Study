#pragma once
#include "pch.h"

#define SINGLE(type) public:\
			static type* Instance()\
			{\
			static type instance;\
			return &instance;\
			}\
			private:\
			type();\
			~type();

#define fDT TimeMgr::Instance()->GetDeltaTimeF()
#define DT TimeMgr::Instance()->GetDeltaTime()

enum class GROUP_TYPE
{
	DEFAULT,
	PLAYER,
	MISSILE,
	ENEMY,


	END=32,
};

enum class SCENE_TYPE
{
	TOOL,
	START,
	STAGE1,
	STAGE2,

	END,
};