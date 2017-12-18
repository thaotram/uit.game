#pragma once
#include "../Object_Status/Object_Status.h"

enum State_Cloud {
	Sand1,
	Sand2,
	Sand3,
	Sand4,
	Sand5,
	Cloud1,
	Cloud2,
	Cloud3,
	Cloud4
};

class Object_Status_Cloud final : public Object_Status
{
public:
	State_Cloud mStateCloud;
	Object_Status_Cloud(State_Cloud c);
	~Object_Status_Cloud();
	void ObjectUpdateEvent(float delay);

};

