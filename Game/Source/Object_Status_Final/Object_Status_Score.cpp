#include "Object_Status_Score.h"
#define mAni	mAnimation
#define mPos	mPosition


Object_Status_Score::Object_Status_Score() : Object_Status("Status") {
	mAni.Set("s_apple", 1);
}

void Object_Status_Score::ObjectUpdateEvent(float delay) {
	mPos << Scene::mScene->mCamera.VECTOR2() + V2{ 0  , 0 };
}
