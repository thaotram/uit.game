#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../Scene/Scene.h"

class Object_Unit_Static_Block_Drop final : public Object_Unit {
private:
	bool isDrop;
	float mX, mY;
	float mTimeCount;

	void NewBlock();
public:
	Object_Unit_Static_Block_Drop(float x, float y);
	~Object_Unit_Static_Block_Drop() {};
	void ObjectUpdateEvent(float delay);
	void ObjectIntersect(Object * pObject);
};
