#pragma once
#include "../Object_Status/Object_Status.h"

enum State_Cloud {
	Cloud4,
	Cloud3,
	Cloud2,
	Cloud1,
	Sand5,
	Sand4,
	Sand3,
	Sand2,
	Sand1,
};

class Object_Status_Cloud final : public Object_Status
{
public:
	State_Cloud mStateCloud;
	Object_Status_Cloud(State_Cloud c);
	~Object_Status_Cloud() {};
	void ObjectUpdateEvent(float delay);

};

