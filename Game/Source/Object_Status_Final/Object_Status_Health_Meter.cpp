#include "Object_Status_Health_Meter.h"
#define mAni	mAnimation
#define mPos	mPosition

Object_Status_Health_Meter::Object_Status_Health_Meter() : Object_Status("Status") {
	mAni.Set("magic_lamp", 1);
}

void Object_Status_Health_Meter::ObjectUpdateEvent(float delay)
{
	mPos <<mScene->mCamera.VECTOR2()+ V2{ 18  , 20 };
}
