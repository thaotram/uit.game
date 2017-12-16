#include "Object_Unit_Static_Genie_Bonus.h"


#define mAni	mAnimation
#define mPos	mPosition
Object_Unit_Static_Genie_Bonus::Object_Unit_Static_Genie_Bonus(float x, float y) : Object_Unit("Item") {
	mPos << V2{ x , y };
	mAni.Set("geniebonus", 1);
	mTimePerFrame = 0.08f;
	mAutoNextFrame = true;
}

void Object_Unit_Static_Genie_Bonus::ObjectUpdateEvent(float dt)
{
}

void Object_Unit_Static_Genie_Bonus::ObjectIntersect(Object * pObject)
{
	mScene->mScore += 250;
	mScene->AddToRemoveList(this);
}
