#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../Scene/Scene.h"

class Object_Unit_Static_Knife final : public Object_Unit {
public:
	Object_Unit_Static_Knife();
	~Object_Unit_Static_Knife() {};
	void ObjectUpdateEvent(float delay);
	void ObjectIntersect(Object * pObject);
};

