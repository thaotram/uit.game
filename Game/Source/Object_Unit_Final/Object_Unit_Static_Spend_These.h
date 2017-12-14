#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../Scene/Scene.h"

class Object_Unit_Static_Spend_These final : public Object_Unit {
private:
	bool mFlip;
public:
	Object_Unit_Static_Spend_These(float x, float y);
	~Object_Unit_Static_Spend_These() {};

	void ObjectUpdateEvent(float dt);
};

