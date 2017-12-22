#include "Object_Status_Spendthese.h"
#define mAni	mAnimation
#define mPos	mPosition


Object_Status_Spendthese::Object_Status_Spendthese() : Object_Status("Status") {
	mAni.Set("spendthese", 1);
}

void Object_Status_Spendthese::ObjectUpdateEvent(float delay) {
	if (Scene::mScene->mSpendthese <= 0) {
		mAni.SetCycleIndex(2);
	}
	else {
		mAni.SetCycleIndex(1);
	}mPos << Scene::mScene->mCamera.VECTOR2() + V2{ 234  , 192 };
}
