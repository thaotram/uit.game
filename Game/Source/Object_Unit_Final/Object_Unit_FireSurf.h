#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../GameDebug.h"

class Object_Unit_FireSurf final : public Object_Unit{
private:
	bool mFlip;
public:
	Object_Unit_FireSurf(float x, float y, bool isFlip);
	~Object_Unit_FireSurf();
	void ObjectIntersect(Object * pObject);
	void ObjectUpdateEvent(float dt);
};

