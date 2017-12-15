#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../Scene/Scene.h"

class Object_Unit_Static_Genie_Bonus final : public Object_Unit {
public:
	Object_Unit_Static_Genie_Bonus(float x, float y);
	~Object_Unit_Static_Genie_Bonus() {};
	void ObjectUpdateEvent(float delay);
	void ObjectIntersect();
};

