#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../Scene/Scene.h"

class Object_Unit_Static_Extra_Health final : public Object_Unit {
private:
	bool mFlip;
public:
	Object_Unit_Static_Extra_Health(float x, float y);
	~Object_Unit_Static_Extra_Health() {};

	void ObjectUpdateEvent(float dt);
};

