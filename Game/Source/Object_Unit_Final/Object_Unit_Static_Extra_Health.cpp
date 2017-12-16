#include "Object_Unit_Static_Extra_Health.h"
#define mAni	mAnimation
#define mPos	mPosition
Object_Unit_Static_Extra_Health::Object_Unit_Static_Extra_Health(float x, float y) : Object_Unit("Item") {
	mPos << V2{ x , y };
	mAni.Set("extrahealth", 1);
	mTimePerFrame = 0.01f;
	mAutoNextFrame = true;
}

void Object_Unit_Static_Extra_Health::ObjectUpdateEvent(float dt)
{

}

void Object_Unit_Static_Extra_Health::ObjectIntersect(Object * pObject)
{
	mScene->mScore += 150;
	mScene->mBlood = min(mScene->mBlood + 1,8);
	mScene->AddToRemoveList(this);
}