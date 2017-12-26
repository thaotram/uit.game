#pragma once
#include "../Object_Map/Object_Map.h"
class Object_Map_Items_Front final : public Object_Map {
public:
	Object_Map_Items_Front();
	void ObjectUpdateEvent(float delay);
};
