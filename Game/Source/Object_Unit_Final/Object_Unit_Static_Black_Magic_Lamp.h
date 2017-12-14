#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../Scene/Scene.h"

class Object_Unit_Static_Black_Magic_Lamp final : public Object_Unit {
private:
	bool mFlip;
public:
	Object_Unit_Static_Black_Magic_Lamp(float x, float y);
	~Object_Unit_Static_Black_Magic_Lamp() {};

	void ObjectUpdateEvent(float dt);
};

