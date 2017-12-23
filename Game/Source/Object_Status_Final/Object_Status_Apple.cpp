#include "Object_Status_Apple.h"
#define mAni	mAnimation
#define mPos	mPosition

Object_Status_Apple::Object_Status_Apple() : Object_Status("Status") {
	mAni.Set("s_apple", 2);
	mIsFlicker = true;
}

void Object_Status_Apple::ObjectUpdateEvent(float delay) {
	if (Scene::mScene->mApple <= 0) {
		mAni.SetCycleIndex(2);
	}
	else {
		mAni.SetCycleIndex(1);
	}
	mPos << Scene::mScene->mCamera.VECTOR2() + V2{ 270  , 192 };
}