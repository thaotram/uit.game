#pragma once
#include "../Object_Unit_Final/Object_Unit_Disappear.h"
#include "../Object_Unit/Object_Unit.h"
#include "../GameDebug.h"
#include "../Scene/Scene.h"

class Object_Unit_Enemy_Straw final : public Object_Unit{
private:
	RECT mLimit;
	bool isPlay;
public:
	Object_Unit_Enemy_Straw(RECT u);
	~Object_Unit_Enemy_Straw();
	void ObjectUpdateEvent(float dt);
	void ObjectEachState();
	void ObjectIntersect(Object * pObject);
};
