#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../GameDebug.h"

class Object_Unit_Explosion_Tiny final : public Object_Unit {
public:
	Object_Unit_Explosion_Tiny(float x, float y);
	~Object_Unit_Explosion_Tiny();

	void ObjectUpdateEvent(float dt);
};

