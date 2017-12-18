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
		if (mNumL == 0) {
			mAni.SetCycleIndex(11);
			break;
		}
		else {
			mNumL %= 10;
			mAni.SetCycleIndex(mNumL + 1);
			break;
		}
	case 2:
		if (mNumL < 10) {
			mAni.SetCycleIndex(11);
			break;
		}
		else {
			mNumL /= 10;
			mNumL %= 10;
			mAni.SetCycleIndex(mNumL + 1);
			break;
		}
	case 3:
		if (mNumL < 100) {
			mAni.SetCycleIndex(11);
			break;
		}
		else {
			mNumL /= 100;
			mNumL %= 10;
			mAni.SetCycleIndex(mNumL + 1);
			break;
		}
	case 4:
		if (mNumL < 1000) {
			mAni.SetCycleIndex(11);
			break;
		}
		else {
			mNumL /= 1000;
			mAni.SetCycleIndex(mNumL + 1);
			break;
		}

	}
	mPos << mScene->mCamera.VECTOR2() + V2{ mX , mY };
}
