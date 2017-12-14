#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../Scene/Scene.h"

class Object_Unit_Static_Restart_Point final : public Object_Unit {
public:
	Object_Unit_Static_Restart_Point(float x, float y);
	~Object_Unit_Static_Restart_Point() {};
	void ObjectUpdateEvent(float delay);
};

