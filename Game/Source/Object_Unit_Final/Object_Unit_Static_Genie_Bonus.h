#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../Scene/Scene.h"
#include "../Object_Unit_Final/Object_Unit_Explosion_Small.h"


class Object_Unit_Static_Genie_Bonus final : public Object_Unit {
private:
	GameSound* mWow;
public:
	Object_Unit_Static_Genie_Bonus(RECT u);
	~Object_Unit_Static_Genie_Bonus() {};
	void ObjectUpdateEvent(float delay);
	void ObjectIntersect(Object * pObject);
};

