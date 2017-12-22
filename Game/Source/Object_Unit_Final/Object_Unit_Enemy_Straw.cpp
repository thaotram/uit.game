#include "Object_Unit_Enemy_Straw.h"
#define mAni	mAnimation
#define mPos	mPosition
#define	mObjectStore	Scene::mScene->oObjectStore
#define isFlip			(mTransform.GetFlip())

#define xx mPos.x()
#define yy mPos.y()
#define state	mAni.GetState()

Object_Unit_Enemy_Straw::Object_Unit_Enemy_Straw(RECT u) : Object_Unit("CivilianEnemies"), mLimit(u) {
	mPos.x << (float)(u.left + u.right) / 2;
	mPos.y << (float)(u.top);
	mPos.x.mVelocity = 40;
	mTimePerFrame = 0.07f;
	mAni.Set("straw_stand", 1);
	mParty = Enemy;
	mAutoNextFrame = true;
}

Object_Unit_Enemy_Straw::~Object_Unit_Enemy_Straw()
{
}

void Object_Unit_Enemy_Straw::ObjectUpdateEvent(float dt)
{
	tUnit = RECT{
		(LONG)xx - 15,
		(LONG)yy - 39,
		(LONG)xx + 15,
		(LONG)yy
	};
	tDis = mObjectStore->GetDistance(tUnit, this);
	tDt = dt;
	ObjectEachState();
}
//tam danh
#define range 50
//tamnhin
#define visible 160
void Object_Unit_Enemy_Straw::ObjectEachState()
{
	float playerX = Scene::mScene->oPlayer->GetPosition()->x();
	mTransform.SetFlip(playerX < xx);
	float distance = abs(xx - playerX);

	if (state == "straw_run") {
		mPos.x += playerX > xx ?
			+(mPos.x.mVelocity * tDt) :
			-(mPos.x.mVelocity * tDt);
		mPos.Update(tDt);
		if (xx < mLimit.left) {
			mPos.x << mLimit.left;
		}
		else if (xx > mLimit.right) {
			mPos.x << mLimit.right;
		}
	}
	if (distance < range) {
		if (state != "straw_hit")		mAni.Set("straw_hit", 1);
	}
	else if (distance < visible) {
		if ((xx == mLimit.right && playerX > xx) ||
			(xx == mLimit.left && playerX < xx)) {
			if (state != "straw_stand")		mAni.Set("straw_stand", 1);
		}
		else if (state != "straw_run")		mAni.Set("straw_run", 1);
	}
	else {
		if (state != "straw_stand")		mAni.Set("straw_stand", 1);
	}
	//else if (state == "straw_hit") {
	//	if (mAni.GetCycleIndex() == 4) {
	//		tUnitDamage = RECT{
	//			(LONG)((isFlip) ? (xx - 42) : (xx + 5)),
	//			(LONG)(yy - 36),
	//			(LONG)((isFlip) ? (xx - 5) : (xx + 42)),
	//			(LONG)(yy - 24)
	//		};
	//	}
	//}
}

void Object_Unit_Enemy_Straw::ObjectGetDame(Object * pObject)
{
	mHealthPoint--;
	if (mHealthPoint <= 0) {
		mIsMarkedDelete = true;
		Scene::mScene->oObjectStore->mLost.push_back(new Object_Unit_Disappear(mPos.x() - 3, mPos.y() - 4));
	}
}
