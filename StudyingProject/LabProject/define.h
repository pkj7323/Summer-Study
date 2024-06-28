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