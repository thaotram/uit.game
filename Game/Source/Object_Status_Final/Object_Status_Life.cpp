#include "Object_Status_Life.h"

#define mAni	mAnimation
#define mPos	mPosition
#define speedX	490
Object_Status_Life::Object_Status_Life() : Object_Status("Status") {
	mPos << V2{ 200  , 600 };
	mAni.Set("s_apple", 1);
}