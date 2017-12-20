#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../GameDebug.h"

class Object_Unit_Disappear final : public Object_Unit{
public:
	Object_Unit_Disappear(float x, float y);
	~Object_Unit_Disappear();

	void ObjectUpdateEvent(float dt);
};

