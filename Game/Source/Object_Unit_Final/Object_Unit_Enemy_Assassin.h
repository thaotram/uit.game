#pragma once
#include "../Object_Unit_Final/Object_Unit_Disappear.h"
#include "../Object_Unit/Object_Unit.h"
#include "../GameDebug.h"

class Object_Unit_Enemy_Assassin final : public Object_Unit
{
private:
	bool mIsThrow;
public:
	Object_Unit_Enemy_Assassin(RECT u);
	~Object_Unit_Enemy_Assassin() {};
	void ObjectUpdateEvent(float dt);
	void ObjectEachState();
	void ObjectIntersect(Object * pObject);
};
