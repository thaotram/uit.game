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
	mNumL = (int)(mScene->mScore());
	switch (mA) {
	case 1:
		mNumL %= 10;
		mAni.SetCycleIndex(mNumL + 1);
		break;
	case 2:
		mNumL /= 10;
		mNumL %= 10;
		mAni.SetCycleIndex(mNumL + 1);
		break;
	case 3:
		mNumL /= 100;
		mNumL %= 10;
		mAni.SetCycleIndex(mNumL + 1);
		break;
	case 4:
		mNumL /= 1000;
		mAni.SetCycleIndex(mNumL + 1);
		break;
	}
	mPos << mScene->mCamera.VECTOR2() + V2{ mX , mY };
}
