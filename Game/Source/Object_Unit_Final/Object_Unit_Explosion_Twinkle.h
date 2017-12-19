#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../GameDebug.h"

class Object_Unit_Explosion_Twinkle final:public Object_Unit
{
public:
	Object_Unit_Explosion_Twinkle(float x, float y,bool isFlip);
	~Object_Unit_Explosion_Twinkle();

	void ObjectUpdateEvent(float dt);
};

