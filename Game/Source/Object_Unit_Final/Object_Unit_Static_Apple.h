#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../Scene/Scene.h"
#include "../Object_Unit_Final/Object_Unit_Explosion_Twinkle.h"

class Object_Unit_Static_Apple final : public Object_Unit {
public:
	Object_Unit_Static_Apple(RECT u);
	~Object_Unit_Static_Apple() {};
	void ObjectUpdateEvent(float delay);
	void ObjectIntersect(Object * pObject);
};

