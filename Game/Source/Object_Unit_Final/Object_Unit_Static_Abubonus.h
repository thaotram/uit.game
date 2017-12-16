#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../Scene/Scene.h"

class Object_Unit_Static_Abubonus final : public Object_Unit {
public:
	Object_Unit_Static_Abubonus(float x, float y);
	~Object_Unit_Static_Abubonus() {};
	void ObjectUpdateEvent(float delay);
	void ObjectIntersect(Object * pObject);
};
