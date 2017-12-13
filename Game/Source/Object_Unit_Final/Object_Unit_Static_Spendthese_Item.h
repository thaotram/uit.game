#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../Scene/Scene.h"

class Object_Unit_Static_Spendthese_Item final : public Object_Unit {
private:
	bool mFlip;
public:
	Object_Unit_Static_Spendthese_Item(float x, float y);
	~Object_Unit_Static_Spendthese_Item() {};

	void ObjectUpdateEvent(float dt);
};

