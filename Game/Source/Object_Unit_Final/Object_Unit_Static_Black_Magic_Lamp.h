#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../Scene/Scene.h"
#include "../Object_Unit_Final/Object_Unit_Explosion_Big.h"

class Object_Unit_Static_Black_Magic_Lamp final : public Object_Unit {
public:
	Object_Unit_Static_Black_Magic_Lamp(RECT u);
	~Object_Unit_Static_Black_Magic_Lamp() {}
	void ObjectIntersect(Object * pObject);
	void ObjectUpdateEvent(float delay);
};

