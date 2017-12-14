#include "Object_Status_Life.h"

#define mAni	mAnimation
#define mPos	mPosition
#define speedX	490
Object_Status_Life::Object_Status_Life() : Object_Status("Status") {
	mAni.Set("1up", 1);
}

void Object_Status_Life::ObjectUpdateEvent(float delay)
{
	mPos << mScene->mCamera.VECTOR2() + V2{ 17  , 184 };
}
