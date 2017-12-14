#include "Object_Status_Health_Meter.h"
#define mAni	mAnimation
#define mPos	mPosition
#define speedX	490

Object_Status_Health_Meter::Object_Status_Health_Meter() : Object_Status("Status") {
	mPos << V2{ 200  , 600 };
	mAni.Set("magic_lamp", 1);
}