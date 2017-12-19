#include "Object_Status_Apple.h"
#define mAni	mAnimation
#define mPos	mPosition


Object_Status_Apple::Object_Status_Apple() : Object_Status("Status") {
	mAni.Set("s_apple", 1);
}

void Object_Status_Apple::ObjectUpdateEvent(float delay){
	mPos << Scene::mScene->mCamera.VECTOR2()+ V2{ 270  , 192 };
}
