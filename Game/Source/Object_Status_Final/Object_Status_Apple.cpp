#include "Object_Status_Apple.h"
#define mAni	mAnimation
#define mPos	mPosition
#define speedX	490

Object_Status_Apple::Object_Status_Apple() : Object_Status("Status") {
	mPos << V2{ 200  , 600 };
	mAni.Set("s_apple", 1);
}