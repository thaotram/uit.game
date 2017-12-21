#pragma once
#include "../Object_Status/Object_Status.h"

enum S_Number_Position {
	S_Apple_Ones,
	S_Apple_Tens,
	S_Spendthese,
	S_Life
}; 

class Object_Status_Number_S final : public Object_Status {
private:
	int mNumber;
	float mX, mY;
public:
	S_Number_Position mNumber_Position;
	Object_Status_Number_S(S_Number_Position a);
	~Object_Status_Number_S() {};
	void ObjectUpdateEvent(float delay);
};

