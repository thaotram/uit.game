#include "Object_Unit_Static_Abubonus.h"
#define mAni	mAnimation
#define mPos	mPosition
Object_Unit_Static_Abubonus::Object_Unit_Static_Abubonus(float x, float y) : Object_Unit("Item") {
	mPos << V2{ x , y };
	mAni.Set("abubonus", 1);
	mAutoNextFrame = false;
}

void Object_Unit_Static_Abubonus::ObjectUpdateEvent(float delay)
{
}

