#pragma once
#include "../GameDebug.h"
#include "../Object_Unit/Object_Unit.h"


class Object_Unit_NPC_Camel final : public Object_Unit {
private:
	bool mIsSpitOut;
public:
    Object_Unit_NPC_Camel(RECT u);
    ~Object_Unit_NPC_Camel(){};

    void StartAnimation();
	void ObjectUpdateEvent(float dt);
};