#pragma once
#include "../Object_Unit/Object_Unit.h"

class Object_Unit_Savila final :public Object_Unit 
{
public:
	Object_Unit_Savila(float x, float y);
	~Object_Unit_Savila();
	void ObjectUpdateEvent(float dt);
};

