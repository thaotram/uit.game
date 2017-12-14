#include "Object_Unit_Static_Genie_Bonus.h"
#define mAni	mAnimation
#define mPos	mPosition
#define speedX	490
Object_Unit_Static_Genie_Bonus::Object_Unit_Static_Genie_Bonus(float x, float y) : Object_Unit("Item") {
	mPos << V2{ 4600 , MAP_HEIGHT - 90 };
	//mPos << V2{ 1900, 400 };
	mAni.Set("geniebonus", 1);
	mAutoNextFrame = false;
}

void Object_Unit_Static_Genie_Bonus::ObjectUpdateEvent(float dt)
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