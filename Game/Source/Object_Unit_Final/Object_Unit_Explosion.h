#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../GameDebug.h"

class Object_Unit_Explosion final : public Object_Unit {
public:
	Object_Unit_Explosion(float x, float y);
	~Object_Unit_Explosion();

	void ObjectUpdateEvent(float dt);
};

