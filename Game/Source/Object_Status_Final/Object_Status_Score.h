#pragma once
#include "../Object_Status/Object_Status.h"

class Object_Status_Score final : public Object_Status {
public:
	Object_Status_Score();
	~Object_Status_Score() {};
	void ObjectUpdateEvent(float delay);
};

