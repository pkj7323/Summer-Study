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

#define Vec2_Zero Vec2(0.f,0.f)
#define Vec2_One Vec2(1.f,1.f)
#define Vec2_Up Vec2(0.f,-1.f)
#define Vec2_Down Vec2(0.f,1.f)
#define Vec2_Left Vec2(-1.f,0.f)
#define Vec2_Right Vec2(1.f,0.f)

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
