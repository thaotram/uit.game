#pragma once
#include "../Object_Map/Object_Map.h"
class Object_Map_Scene_Start final : public Object_Map {
public:
	Object_Map_Scene_Start();
	void ObjectUpdateEvent(float delay);
};
