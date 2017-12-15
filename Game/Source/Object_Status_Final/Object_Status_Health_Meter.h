#pragma once
#include "../Object_Status/Object_Status.h"

class Object_Status_Health_Meter final : public Object_Status {
public:
	Object_Status_Health_Meter(int i);
	~Object_Status_Health_Meter() {};
	void ObjectUpdateEvent(float delay);

};

