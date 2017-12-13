#include "Object_Unit_Static_Geniebonus.h"
#define mAni	mAnimation
#define mPos	mPosition
#define speedX	490
Object_Unit_Geniebonus::Object_Unit_Geniebonus(float x, float y) : Object_Unit("Item") {
	mPos << V2{ 4600 , MAP_HEIGHT - 90 };
	//mPos << V2{ 1900, 400 };
	mAni.Set("apple_item", 1);
	mAutoNextFrame = false;
}

void Object_Unit_Geniebonus::ObjectUpdateEvent(float dt)
{
	if (mAni.GetCycleIndex() == 6)
	{
		//mScene->Remove("2");
	}

	if (mAutoNextFrame) {
		mPos.x += speedX * dt * (mFlip ? -1 : 1);
		mPos.y = MAP_HEIGHT;

		mPos.x.Update(dt);
		mPos.y.Update(dt);
	}
}