#include "Object_Status_Number_S.h"
#define mAni mAnimation
#define mPos mPosition

Object_Status_Number_S::Object_Status_Number_S(S_Number_Position pNumber_Position)
    : Object_Status("Status") {
    mNumber_Position = pNumber_Position;
    mAni.Set("number_s", 11);

    switch (mNumber_Position) {
        case S_Apple_Ones:
            mX = 296;
            mY = 200;
            break;
        case S_Apple_Tens:
            mX = 288;
            mY = 200;
            break;
        case S_Spendthese:
            mX = 253;
            mY = 200;
            break;
        case S_Life:
            mX = 42;
            mY = 200;
            break;
    }
}

void Object_Status_Number_S::ObjectUpdateEvent(float delay)
{
	switch (mNumber_Position) {
	case S_Apple_Ones:
		if (Scene::mApple < 10)
			mAni.SetCycleIndex(11);
		else {
			mNumber = Scene::mApple % 10;
			mAni.SetCycleIndex(mNumber + 1);
		}
		break;
	case S_Apple_Tens:
		if (Scene::mApple <= 0) {
			mAni.SetCycleIndex(11);
		}
		else if (Scene::mApple < 10 && Scene::mApple>0) {
			mNumber = Scene::mApple;
			mAni.SetCycleIndex(mNumber + 1);
		}
		else {
			mNumber = Scene::mApple / 10;
			mAni.SetCycleIndex(mNumber + 1);
		}
		break;
	case S_Spendthese:
		mNumber = Scene::mSpendthese;
		if (mNumber == 0) {
			mAni.SetCycleIndex(11);
		}
		else {
			mAni.SetCycleIndex(mNumber + 1);
		}
		break;
	case S_Life:
		if (Scene::mExtrahealth == 0) {
			mAni.SetCycleIndex(11);
		}
		else {
			mAni.SetCycleIndex(Scene::mExtrahealth + 1);
		}
		break;
	}
	mPos << Scene::mScene->mCamera.VECTOR2() + V2{ mX , mY };
}