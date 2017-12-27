#pragma once
#include "../GameDebug.h"
#include "../Object_Unit/Object_Unit.h"

class Object_Unit_Jar_Copper final : public Object_Unit {
private:
	bool mFlip;
	bool mIsCollision;

public:
	Object_Unit_Jar_Copper(float x, float y);
	~Object_Unit_Jar_Copper() {};

	void ObjectUpdateEvent(float dt);
	void ObjectIntersect(Object * pObject);
};
