#pragma once
#include "../Object_Status/Object_Status.h"
class Object_Status_Life final : public Object_Status
{
public:
	Object_Status_Life();
	~Object_Status_Life() {};
	void ObjectUpdateEvent(float delay);
};

