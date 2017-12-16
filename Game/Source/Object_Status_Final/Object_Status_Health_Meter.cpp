#include "Object_Status_Health_Meter.h"
#define mAni	mAnimation
#define mPos	mPosition

Object_Status_Health_Meter::Object_Status_Health_Meter(int i) : Object_Status("Status") {
	/// Xét trường hợp health meter nằm ngoài vùng giá trị 1-> 8
	i = i < 1 ? 1 : (i > 8 ? 8 : i);
	mAni.Set("health_meter_"+to_string(i), 1);
	mAutoNextFrame = true;
}

void Object_Status_Health_Meter::ObjectUpdateEvent(float delay)
{

	mPos <<mScene->mCamera.VECTOR2()+ V2{ 66  , 12 };
}
