#include "Object_Status_Number_L.h"
#define mAni mAnimation
#define mPos mPosition

Object_Status_Number_L::Object_Status_Number_L(L_Number_Position pNumber_Position)
    : Object_Status("Status") {
    mAni.Set("number_l", 11);
    mNumber_Position = pNumber_Position;
	switch (mNumber_Position) {
	case L_Score_Ones:
		mX = 275;
		mY = 20;
		break;
	case L_Score_Tens:
		mX = 258;
		mY = 20;
		break;
	case L_Score_Hundreds:
		mX = 241;
		mY = 20;
		break;
	case L_Score_Thousand:
		mX = 224;
		mY = 20;
		break;
	}
}

void Object_Status_Number_L::ObjectUpdateEvent(float delay) {
    mNumber = (int)(Scene::mScore() / 10) * 10;
    switch (mNumber_Position) {
        case L_Score_Ones:
            if (mNumber == 0) {
                mAni.SetCycleIndex(11);
            } else {
                mNumber %= 10;
                mAni.SetCycleIndex(mNumber + 1);
            }
            break;
        case L_Score_Tens:
            if (mNumber < 10) {
                mAni.SetCycleIndex(11);
            } else {
                mNumber /= 10;
                mNumber %= 10;
                mAni.SetCycleIndex(mNumber + 1);
            }
            break;
        case L_Score_Hundreds:
            if (mNumber < 100) {
                mAni.SetCycleIndex(11);
            } else {
                mNumber /= 100;
                mNumber %= 10;
                mAni.SetCycleIndex(mNumber + 1);
            }
            break;
        case L_Score_Thousand:
            if (mNumber < 1000) {
                mAni.SetCycleIndex(11);
            } else {
                mNumber /= 1000;
                mAni.SetCycleIndex(mNumber + 1);
            }
            break;
    }
    mPos << Scene::mScene->mCamera.VECTOR2() + V2{mX, mY};
}
