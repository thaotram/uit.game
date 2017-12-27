#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../GameDebug.h"

class Object_Unit_Fire : public Object_Unit{
private:
	float mTime;
public:
	Object_Unit_Fire(float x, float y);
	~Object_Unit_Fire();
	void ObjectUpdateEvent(float dt);
};

