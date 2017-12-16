#include "Object_Status_Number_S.h"
#define mAni	mAnimation
#define mPos	mPosition

Object_Status_Number_S::Object_Status_Number_S() : Object_Status("Status") {
	mAni.Set("number_s", 1);
}

void Object_Status_Number_S::ObjectUpdateEvent(float delay)
{

	mAni.SetCycleIndex(mNums + 1);
	mPos << mScene->mCamera.VECTOR2() + V2{ 300  , 200 };
}
