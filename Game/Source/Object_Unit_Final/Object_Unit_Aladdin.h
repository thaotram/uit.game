#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../Scene/Scene.h"

class Object_Unit_Aladdin final : public Object_Unit {
private:
	bool
		isJumpUp,
		isGround;
	int lastIndex;


	char leftOrRight;
	float * velocity;
public:
	Object_Unit_Aladdin();
	~Object_Unit_Aladdin() {};

	void ObjectUpdateEvent(float dt);
	void ObjectUpdatePosition(float dt);
};