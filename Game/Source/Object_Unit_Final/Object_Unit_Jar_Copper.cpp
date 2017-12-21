#include "Object_Unit_Jar_Copper.h"
#define mAni mAnimation
#define mPos mPosition
#define mObjectStore Scene::mScene->oObjectStore
#define tSpeedX 400
//#define tSpeedX	490

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_Jar_Copper::Object_Unit_Jar_Copper(float x, float y)
	: Object_Unit("CivilianEnemies") {
	mPos << V2{ x, y };
	mPos.x.mVelocity = 30;
	mAni.Set("jar_copper_fall", 1);

	mTimePerFrame = 0.03f;
	mAutoNextFrame = true;
	mIsCollision = false;
	mIsMakeDamage = false;
	mParty = Enemy;
}

void Object_Unit_Jar_Copper::ObjectUpdateEvent(float dt) {
	//# Tính UnitDamage
	tUnit = RECT{
		(LONG)xx - 14,
		(LONG)yy - 21,
		(LONG)xx + 14,
		(LONG)yy
	};
	tDis = mObjectStore->GetDistance(tUnit, this);
	if (mAni.GetState() == "jar_copper_fall") {
		mPos.x += mPos.x.mVelocity*dt;
		mPos.y = yy + tDis.bottom;
		tUnitDamage = GetBound();
		mPos.Update(dt);
		if (tDis.bottom == 0) {
			mAni.Set("jar_copper_break", 1);
		}
	}
	else if (mAni.GetState() == "jar_copper_break") {
		if (mAni.GetCycleIndex() == 9) {
			mIsMarkedDelete = true;
		}
	}
	Scene::mScene->oObjectStore->ObjectCheckCollisionWithPlayer(this);
}