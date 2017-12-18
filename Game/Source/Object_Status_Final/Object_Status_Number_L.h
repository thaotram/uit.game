#pragma once
#include "../Object_Status/Object_Status.h"

enum L_Number_Position {
	L_Score_Ones,
	L_Score_Tens,
	L_Score_Hundreds,
	L_Score_Thousand
};

class Object_Status_Number_L final : public Object_Status {
private:
	float mX, mY;
public:
	L_Number_Position mLnumber;
	int mNumL;
	Object_Status_Number_L(float x, float y, L_Number_Position a);
	~Object_Status_Number_L() {};
	void ObjectUpdateEvent(float delay);
};

