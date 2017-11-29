#pragma once
#include "../Object_Map/Object_Map.h"

class Object_Map_AgrabahMarket_Back final : public Object_Map {
public:
	Object_Map_AgrabahMarket_Back();
	void ObjectUpdateEvent(float delay);
};