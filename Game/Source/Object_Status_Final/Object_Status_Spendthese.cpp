#include "Object_Status_Spendthese.h"
#define mAni	mAnimation
#define mPos	mPosition
#define speedX	490


Object_Status_Spendthese::Object_Status_Spendthese() : Object_Status("Status") {
	mAni.Set("spendthese", 1);
}

void Object_Status_Spendthese::ObjectUpdateEvent(float delay) {
	mPos << mScene->mCamera.VECTOR2() + V2{ 234  , 192 };
}
