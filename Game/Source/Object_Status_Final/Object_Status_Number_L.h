#pragma once
#include "../Object_Status/Object_Status.h"

class Object_Status_Number_L final : public Object_Status {
private:
	float mX, mY;
	int mA;
public:
	int mNumL;
	Object_Status_Number_L(float x, float y, int a);
	~Object_Status_Number_L() {};
	void ObjectUpdateEvent(float delay);
};

