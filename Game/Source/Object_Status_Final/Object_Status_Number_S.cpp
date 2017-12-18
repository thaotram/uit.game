#include "Object_Status_Number_S.h"
#define mAni	mAnimation
#define mPos	mPosition

Object_Status_Number_S::Object_Status_Number_S(float x, float y, int a) : Object_Status("Status") {
	mX = x;
	mY = y;
	mA = a;
	mAni.Set("number_s", 1);
}

void Object_Status_Number_S::ObjectUpdateEvent(float delay)
{
	switch (mA)
	{
	case 1:
		// táo: đơn vị
		mNums = mScene->mApple % 10;
		mAni.SetCycleIndex(mNums + 1);
		break;
	case 2:
		// táo: chục
		if (mNums < 10) {
			mAni.SetCycleIndex(11);
			break;
		}
		else {
		mNums = mScene->mApple / 10;
		mAni.SetCycleIndex(mNums + 1);
		break;
		}
	case 3:
		// spendthese
		mNums = mScene->mSpendthese;
		mAni.SetCycleIndex(mNums + 1);
		break;
	case 4:
		// life
		mAni.SetCycleIndex(3 + 1);
		break;
	}
	mPos << mScene->mCamera.VECTOR2() + V2{ mX , mY };
}
