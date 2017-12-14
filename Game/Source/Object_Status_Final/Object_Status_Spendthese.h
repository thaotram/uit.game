#pragma once
#include "../Object_Status/Object_Status.h"

class Object_Status_Spendthese final : public Object_Status {
public:
	Object_Status_Spendthese();
	~Object_Status_Spendthese() {};
	void ObjectUpdateEvent(float delay);
};

