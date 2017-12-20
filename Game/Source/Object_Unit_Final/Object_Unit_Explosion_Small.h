#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../GameDebug.h"

class Object_Unit_Explosion_Small : public Object_Unit {
private:
	RECT tDis;
	RECT tUnit;
	bool mFlip;
public:
	Object_Unit_Explosion_Small(float x, float y);
	~Object_Unit_Explosion_Small();
	void ObjectUpdateEvent(float dt);
};

