#include "Object_Unit_Static_Spend_These.h"
#define mAni	mAnimation
#define mPos	mPosition
Object_Unit_Static_Spend_These::Object_Unit_Static_Spend_These(float x, float y) : Object_Unit("Item") {
	mPos << V2{ x , y };
	mAni.Set("spendthese_item", 1);
	mAutoNextFrame = true;
	mIs = false;
}

void Object_Unit_Static_Spend_These::ObjectUpdateEvent(float dt)
{
}

void Object_Unit_Static_Spend_These::ObjectIntersect(Object * pObject)
{
	mAni.SetCycleIndex(10);
	if (!mIs) {
		mIs = true;
		mScene->mSpendthese++;
		mAutoNextFrame = false;
	}

}
