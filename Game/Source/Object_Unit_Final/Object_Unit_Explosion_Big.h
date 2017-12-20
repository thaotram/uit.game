#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../GameDebug.h"

class Object_Unit_Explosion_Big final: public Object_Unit{
public:
	Object_Unit_Explosion_Big(float x, float y);
	~Object_Unit_Explosion_Big();

	void ObjectUpdateEvent(float dt);
};

