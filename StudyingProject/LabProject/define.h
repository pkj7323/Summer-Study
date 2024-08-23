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

#define KEY_CHECK(key, state) KeyMgr::Instance()->GetKeyState(key) == state
#define KEY_HOLD(key) KEY_CHECK(key, KEY_STATE::HOLD)
#define KEY_AWAY(key) KEY_CHECK(key, KEY_STATE::AWAY)
#define KEY_TAP(key) KEY_CHECK(key, KEY_STATE::TAP)
#define KEY_NONE(key) KEY_CHECK(key, KEY_STATE::NONE)


#define fDT TimeMgr::Instance()->GetDeltaTimeF()
#define DT TimeMgr::Instance()->GetDeltaTime()

#define Vec2_Zero Vec2(0.f,0.f)
#define Vec2_One Vec2(1.f,1.f)
#define Vec2_Up Vec2(0.f,-1.f)
#define Vec2_Down Vec2(0.f,1.f)
#define Vec2_Left Vec2(-1.f,0.f)
#define Vec2_Right Vec2(1.f,0.f)

#define PI 3.14159274101257324219f
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

enum class ResourceType	
{
	TEXTURE,
	ANIMATION,
	SOUND,
	END,
};

enum class ComponentType
{
	TRANSFORM,
	SPRITE,
	ANIMATION,
	COLLIDER,
	END=16,
};
