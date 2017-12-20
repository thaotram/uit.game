#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../Object_Unit_Final/Object_Unit_Explosion_Tiny.h"
#include "../GameDebug.h"


class Object_Unit_Knife final : public Object_Unit{
private:
	bool mFlip;
	bool mIsCollision;
public:
	Object_Unit_Knife(float x, float y, bool isFlip);
	~Object_Unit_Knife();
	void ObjectIntersect(Object * pObject);
	void ObjectUpdateEvent(float dt);
};

