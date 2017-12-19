#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../GameDebug.h"
#include "../Scene/Scene.h"

class Object_Unit_Enemy_Thin final : public Object_Unit
{
public:
	Object_Unit_Enemy_Thin(RECT u);
	~Object_Unit_Enemy_Thin();
	void ObjectUpdateEvent(float dt);
	void ObjectEachState();
};

