#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../GameDebug.h"

class Object_Unit_NPC_Stall final : public Object_Unit{
private:
	bool isShow;
	bool isPlay;
public:
	Object_Unit_NPC_Stall(RECT u);
	~Object_Unit_NPC_Stall();
	void ObjectUpdateEvent(float dt);
};

