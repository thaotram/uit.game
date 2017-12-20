#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../GameDebug.h"
#include "../Scene/Scene.h"

class Object_Unit_Enemy_Straw final : public Object_Unit
{
public:
	Object_Unit_Enemy_Straw(RECT u);
	~Object_Unit_Enemy_Straw();
	void ObjectUpdateEvent(float dt);
	void ObjectEachState();
};

