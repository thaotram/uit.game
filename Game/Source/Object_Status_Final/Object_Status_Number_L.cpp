#include "Object_Status_Number_L.h"
#define mAni	mAnimation
#define mPos	mPosition

Object_Status_Number_L::Object_Status_Number_L(float x, float y, int a) : Object_Status("Status") {
	mX = x;
	mY = y;
	mA = a;
	mAni.Set("number_l", 1);
}

void Object_Status_Number_L::ObjectUpdateEvent(float delay)
{
	mPos << mScene->mCamera.VECTOR2() + V2{ mX , mY };
}