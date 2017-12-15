#include "Object_Unit_Apple.h"
#define mAni	mAnimation
#define mPos	mPosition
#define tSpeedX	490
Object_Unit_Apple::Object_Unit_Apple(float x, float y, bool flip) : Object_Unit("Aladdin") {
	mPos << V2{ x , y };
	//mPos << V2{ 1900, 400 };
	mFlip = flip;
	mAni.Set("apple", 2);
	mAutoNextFrame = false;
}

void Object_Unit_Apple::ObjectUpdateEvent(float dt)
{
	if (mAni.GetCycleIndex() == 6)
	{
		//mScene->Remove("2");
	}

	if (mAutoNextFrame) {
		mPos.x += tSpeedX * dt * (mFlip ? -1 : 1);
		mPos.y = MAP_HEIGHT;

		mPos.x.Update(dt);
		mPos.y.Update(dt);
	}
}