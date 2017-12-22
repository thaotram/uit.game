#pragma once
#include "../Object_Unit_Final/Object_Unit_Disappear.h"
#include "../Object_Unit/Object_Unit.h"
#include "../GameDebug.h"
#include "../Scene/Scene.h"

class Object_Unit_Enemy_Pirates final : public Object_Unit{
private:
	RECT mLimit;
public:
	Object_Unit_Enemy_Pirates(RECT u);
	~Object_Unit_Enemy_Pirates();
	void ObjectUpdateEvent(float dt);
	void ObjectEachState();
	void ObjectGetDame(Object * pObject);
};
