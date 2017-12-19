#include "Object_Status_Number_S.h"
#define mAni	mAnimation
#define mPos	mPosition

Object_Status_Number_S::Object_Status_Number_S(float x, float y, S_Number_Position a) : Object_Status("Status") {
	mX = x;
	mY = y;
	mSNumber = a;
	mAni.Set("number_s", 1);
}

void Object_Status_Number_S::ObjectUpdateEvent(float delay)
{
	switch (mSNumber)
	{
	case 0:
		mNums = Scene::mScene->mApple % 10;
		mAni.SetCycleIndex(mNums + 1);
		break;
	case 1:
		if (Scene::mScene->mApple < 10) {
			mAni.SetCycleIndex(11);
		}
		else {
			mNums = Scene::mScene->mApple / 10;
			mAni.SetCycleIndex(mNums + 1);
		}
		break;
	case 2:
		mNums = Scene::mScene->mSpendthese;
		mAni.SetCycleIndex(mNums + 1);
		break;
	case 3:
		mAni.SetCycleIndex(3 + 1);
		break;
	}
	mPos << Scene::mScene->mCamera.VECTOR2() + V2{ mX , mY };
}
