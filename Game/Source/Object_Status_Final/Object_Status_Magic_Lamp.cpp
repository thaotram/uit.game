#include "Object_Status_Magic_Lamp.h"
#define mAni	mAnimation
#define mPos	mPosition
#define speedX	490


Object_Status_Magic_Lamp::Object_Status_Magic_Lamp() : Object_Status("Status") {
	mAni.Set("magic_lamp", 1);
}

void Object_Status_Magic_Lamp::ObjectUpdateEvent(float delay) {
	mPos << mScene->mCamera.VECTOR2() + V2{ 18  , 20 };
}
