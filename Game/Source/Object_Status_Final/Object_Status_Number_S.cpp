#include "Object_Status_Number_S.h"
#define mAni	mAnimation
#define mPos	mPosition
#define speedX	490

Object_Status_Number_S::Object_Status_Number_S() : Object_Status("Status") {
	mPos << V2{ 200  , 600 };
	mAni.Set("number_s", 1);
}