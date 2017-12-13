#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../Scene/Scene.h"

class Object_Unit_Black_Magiclamp final : public Object_Unit {
private:
	bool mFlip;
public:
	Object_Unit_Black_Magiclamp(float x, float y);
	~Object_Unit_Black_Magiclamp() {};

	void ObjectUpdateEvent(float dt);
};

