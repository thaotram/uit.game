#pragma once
#include "../Object_Status/Object_Status.h"

class Object_Status_Number_S final : public Object_Status {
public:
	int mNums;
	Object_Status_Number_S();
	~Object_Status_Number_S() {};
	void ObjectUpdateEvent(float delay);
};

