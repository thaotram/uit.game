#include "Object_Unit_Static_Abubonus.h"
#define mAni	mAnimation
#define mPos	mPosition
Object_Unit_Static_Abubonus::Object_Unit_Static_Abubonus(float x, float y) : Object_Unit("Item") {
	mPos << V2{ x , y };
	mAni.Set("abubonus", 1);
	mAutoNextFrame = true;
}

void Object_Unit_Static_Abubonus::ObjectUpdateEvent(float delay)
{
}

void Object_Unit_Static_Abubonus::ObjectIntersect()
{
	mScene->mScore += 250;
	mScene->AddToRemoveList(this);
}

