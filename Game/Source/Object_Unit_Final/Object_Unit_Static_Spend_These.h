#pragma once
#include "../Object_Unit_Final/Object_Unit_Explosion_Twinkle.h"
#include "../Object_Unit/Object_Unit.h"
#include "../Scene/Scene.h"

class Object_Unit_Static_Spend_These final : public Object_Unit {
public:
	Object_Unit_Static_Spend_These(RECT u);
	~Object_Unit_Static_Spend_These() {};
	void ObjectUpdateEvent(float delay);
	void ObjectIntersect(Object * pObject);
};

