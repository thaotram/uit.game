#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../Scene/Scene.h"

class Object_Unit_Geniebonus final : public Object_Unit {
private:
	bool mFlip;
public:
	Object_Unit_Geniebonus(float x, float y);
	~Object_Unit_Geniebonus() {};

	void ObjectUpdateEvent(float dt);
};

