#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../Object_Unit_Final/Object_Unit_Jar_Copper_Fall.h"
#include "../GameDebug.h"

class Object_Unit_Enemy_Assassin final : public Object_Unit
{
public:
	Object_Unit_Enemy_Assassin(RECT u);
	~Object_Unit_Enemy_Assassin();
	void ObjectUpdateEvent(float dt);
	void ObjectEachState();
	void ObjectGetDame(Object * pObject);
};
