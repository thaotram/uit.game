#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../Scene/Scene.h"

class Object_Unit_Static_Extra_Health final : public Object_Unit {
public:
	Object_Unit_Static_Extra_Health(RECT u);
	~Object_Unit_Static_Extra_Health() {};
	void ObjectUpdateEvent(float delay);
	void ObjectIntersect(Object * pObject);
};

