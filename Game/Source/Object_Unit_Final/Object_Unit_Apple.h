#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../GameDebug.h"

class Object_Unit_Apple final : public Object_Unit {
private:
	RECT tDis;
	RECT tUnit;
	bool mFlip;
public:
	Object_Unit_Apple(float x, float y);
	~Object_Unit_Apple() {};

	bool mIsThrow;
	void ObjectUpdateEvent(float dt);
	void ThrowApple(bool flip);
};

