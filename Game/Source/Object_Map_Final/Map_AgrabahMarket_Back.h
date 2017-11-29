#pragma once
#include "../Object_Map/Object_Map.h"

class Map_AgrabahMarket_Back final : public Object_Map {
public:
	Map_AgrabahMarket_Back();
	void ObjectUpdateEvent(float delay);
};