#include "Object_Unit_Enemy_Pirates.h"
#define mAni	mAnimation
#define mPos	mPosition
#define	mObjectStore	Scene::mScene->oObjectStore
#define isFlip			(mTransform.GetFlip())

#define xx mPos.x()
#define yy mPos.y()
#define state	mAni.GetState()

Object_Unit_Enemy_Pirates::Object_Unit_Enemy_Pirates(RECT u) : Object_Unit("Guards"), mLimit(u){
	mPos.x << (float)(u.left + u.right) / 2;
	mPos.y << (float)(u.top);
	mAni.Set("pirates_defiant", 1);
	mPos.x.mVelocity = 180;
	mTimePerFrame = 0.04f;
	mParty = Enemy;
	mAutoNextFrame = true;
}

Object_Unit_Enemy_Pirates::~Object_Unit_Enemy_Pirates()
{
}

void Object_Unit_Enemy_Pirates::ObjectUpdateEvent(float dt)
{
	tUnit = RECT{
		(LONG)xx - 11,
		(LONG)yy - 52,
		(LONG)xx + 11,
		(LONG)yy
	};
	tDis = mObjectStore->GetDistance(tUnit, this);
	tDt = dt;
	ObjectEachState();
}
//tam danh
#define range 100
//tamnhin
#define visible 160
void Object_Unit_Enemy_Pirates::ObjectEachState()
{
	float playerX = Scene::mScene->oPlayer->GetPosition()->x();
	mTransform.SetFlip(playerX > xx);
	float distance = abs(xx - playerX);

	if (state == "pirates_run") {
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

	if (state != "pirates_hurt") {
		if (distance < range) {
			if (state != "pirates_cut")		mAni.Set("pirates_cut", 1);
		}
		else if (distance < visible) {
			if ((xx == mLimit.right && playerX > xx) ||
				(xx == mLimit.left && playerX < xx)) {
				if (state != "pirates_defiant")		mAni.Set("pirates_defiant", 1);
			}
			else if (state != "pirates_run")		mAni.Set("pirates_run", 1);
		}
		else {
			if (state != "pirates_defiant")		mAni.Set("pirates_defiant", 1);
		}
	}
	//else if (state == "pirates_poke") {
	//	if (mAni.GetCycleIndex() == 6) {
	//		tUnitDamage = RECT{
	//			(LONG)((isFlip) ? (xx + 75) : (xx - 18)),
	//			(LONG)(yy - 23),
	//			(LONG)((isFlip) ? (xx + 18) : (xx - 75)),
	//			(LONG)(yy - 10)
	//		};
	//	}
	//}
	//else if (state == "pirates_cut") {
	//	if (mAni.GetCycleIndex() == 4) {
	//		tUnitDamage = RECT{
	//			(LONG)((isFlip) ? (xx - 27) : (xx - 83)),
	//			(LONG)(yy - 52),
	//			(LONG)((isFlip) ? (xx + 83) : (xx + 27)),
	//			(LONG)(yy - 25)
	//		};
	//	}
	//}
}

void Object_Unit_Enemy_Pirates::ObjectGetDame(Object * pObject)
{
	mHealthPoint--;
	mAni.Set("pirates_hurt", 1, "pirates_defiant", 1);
	if (mHealthPoint <= 0) {
		mIsMarkedDelete = true;
		Scene::mScene->oObjectStore->mLost.push_back(new Object_Unit_Disappear(mPos.x() - 3, mPos.y() - 4));
	}
}
