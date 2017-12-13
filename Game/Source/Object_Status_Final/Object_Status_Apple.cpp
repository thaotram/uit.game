#include "Object_Status_Apple.h"
#define mAni	mAnimation
#define mPos	mPosition
#define speedX	490
Object_Status_Apple::Object_Status_Apple() : Object_Status("Status") {
	mPos << V2{200  , 600 };
	//mPos << V2{ 1900, 400 };
	mAni.Set("s_apple", 1);
	mAutoNextFrame = false;
}

void Object_Status_Apple::ObjectUpdateEvent(float dt)
{
	mPos.x.Update(dt);
	mPos.y.Update(dt);
}