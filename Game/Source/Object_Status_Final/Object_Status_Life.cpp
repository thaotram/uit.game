#include "Object_Status_Life.h"

#define mAni	mAnimation
#define mPos	mPosition
Object_Status_Life::Object_Status_Life() : Object_Status("Status") {
	mAni.Set("1up", 1);
	mAutoNextFrame = false;
}

void Object_Status_Life::ObjectUpdateEvent(float delay) {
	mPos << Scene::mScene->mCamera.VECTOR2() + V2{ 17  , 185 };
	if (Scene::mExtrahealth == 0) {
		mAni.SetCycleIndex(2);
	}
	else {
		mAni.SetCycleIndex(1);
	}
}