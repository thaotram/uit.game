#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../GameDebug.h"
#include "../Object_Unit_Final/Object_Unit_Knife.h"

class Object_Unit_Enemy_Circus final : public Object_Unit
{
private:
	bool mIsThrow;
	bool mIsFlip;
public:
	Object_Unit_Enemy_Circus(RECT u);
	~Object_Unit_Enemy_Circus();
	void ObjectUpdateEvent(float dt);
	void ObjectEachState();
	void ObjectGetDame(Object * pObject);
};

