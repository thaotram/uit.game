#include "Object_Status_Health_Meter.h"
#define mAni	mAnimation
#define mPos	mPosition

Object_Status_Health_Meter::Object_Status_Health_Meter(int i) : Object_Status("Status") {

	mAni.Set("health_meter_"+to_string(i), 1);
	mAutoNextFrame = true;
}

void Object_Status_Health_Meter::ObjectUpdateEvent(float delay)
{
	mPos <<mScene->mCamera.VECTOR2()+ V2{ 66  , 12 };
}
