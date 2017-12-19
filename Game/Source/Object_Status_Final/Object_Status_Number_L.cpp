#include "Object_Status_Number_L.h"
#define mAni	mAnimation
#define mPos	mPosition

Object_Status_Number_L::Object_Status_Number_L(float x, float y, L_Number_Position a) : Object_Status("Status") {
	mX = x;
	mY = y;
	mLnumber = a;
	mAni.Set("number_l", 1);
}

void Object_Status_Number_L::ObjectUpdateEvent(float delay)
{
	mNumL = (int)(mScene->mScore() / 10) * 10;
	switch (mLnumber) {
	case 0:
		if (mNumL == 0) {
			mAni.SetCycleIndex(11);
		}
		else {
			mNumL %= 10;
			mAni.SetCycleIndex(mNumL + 1);
		}
		break;
	case 1:
		if (mNumL < 10) {
			mAni.SetCycleIndex(11);
		}
		else {
			mNumL /= 10;
			mNumL %= 10;
			mAni.SetCycleIndex(mNumL + 1);
		}
		break;
	case 2:
		if (mNumL < 100) {
			mAni.SetCycleIndex(11);
		}
		else {
			mNumL /= 100;
			mNumL %= 10;
			mAni.SetCycleIndex(mNumL + 1);
		}
		break;
	case 3:
		if (mNumL < 1000) {
			mAni.SetCycleIndex(11);
		}
		else {
			mNumL /= 1000;
			mAni.SetCycleIndex(mNumL + 1);
		}
		break;
	}
	mPos << mScene->mCamera.VECTOR2() + V2{ mX , mY };
}
