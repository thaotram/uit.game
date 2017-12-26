#include "Object_Unit_FireSurf.h"
#define mAni	mAnimation
#define mPos	mPosition
#define	mObjectStore	Scene::mScene->oObjectStore

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_FireSurf::Object_Unit_FireSurf(float x, float y, bool isFlip) : Object_Unit("BossJafar") {
	mPos << V2{ x, y + 1 };
	mAni.Set("fire_surf", 1);
	mPos.x.mVelocity = 180;
	mPos.y.mVelocity = 180;
	mTimePerFrame = 0.05f;
	mFlip = isFlip;
	mTransform.SetFlip(mFlip);
	mIsMakeDamage = false;
	mParty = Enemy;
}

Object_Unit_FireSurf::~Object_Unit_FireSurf()
{
}

void Object_Unit_FireSurf::ObjectIntersect(Object * pObject)
{
	mAutoNextFrame = true;
	//	mIsMarkedDelete = true;
}

void Object_Unit_FireSurf::ObjectUpdateEvent(float dt)
{
	tUnitDamage = RECT{
		(LONG)xx - 37,
		(LONG)yy - 10,
		(LONG)xx + 37,
		(LONG)yy
	};
	Scene::mScene->oObjectStore->Collision_Enemy_Player(this);

	if (xx < 65 || xx > 759) {
		mIsMarkedDelete = true;
	}
	mPos.y = 352;
	mPos.x += (mFlip ? -1 : 1) * mPos.x.mVelocity * dt;
	mPos.Update(dt);
}