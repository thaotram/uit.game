#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../GameDebug.h"

class Object_Unit_Knife final : public Object_Unit{
public:
	Object_Unit_Knife(float x, float y);
	~Object_Unit_Knife();
	void ObjectUpdateEvent(float dt);
	void ThrowKnife(bool flip);

};

