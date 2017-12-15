#pragma once
#include "../Object_Status/Object_Status.h"

class Object_Status_Magic_Lamp final : public Object_Status {
public:
	Object_Status_Magic_Lamp();
	~Object_Status_Magic_Lamp() {};
	void ObjectUpdateEvent(float delay);
};

