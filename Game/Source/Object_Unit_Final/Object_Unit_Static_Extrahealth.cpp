#include "Object_Unit_Static_Extrahealth.h"
#define mAni	mAnimation
#define mPos	mPosition
#define speedX	490
Object_Unit_Static_Extrahealth::Object_Unit_Static_Extrahealth(float x, float y) : Object_Unit("Item") {
	mPos << V2{ x , y };
	//mPos << V2{ 1900, 400 };
	mAni.Set("extrahealth", 1);
	mAutoNextFrame = false;
}

void Object_Unit_Static_Extrahealth::ObjectUpdateEvent(float dt)
{

}