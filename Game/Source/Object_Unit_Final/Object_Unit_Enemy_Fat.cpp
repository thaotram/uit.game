#include "Object_Unit_Enemy_Fat.h"
#define mAni mAnimation
#define mPos mPosition
#define mObjectStore Scene::mScene->oObjectStore

#define xx mPos.x()
#define yy mPos.y()
#define state mAni.GetState()

Object_Unit_Enemy_Fat::Object_Unit_Enemy_Fat(RECT u) : Object_Unit("Guards"), mLimit(u) {
	mPos.x << (float)(u.left + u.right) / 2;
	mPos.y << (float)(u.top);
	mAni.Set("fat_eat", 1);
	mPos.x.mVelocity = 50;
	mParty = Enemy;
}

void Object_Unit_Enemy_Fat::ObjectUpdateEvent(float dt) {
	tUnit = RECT{
		(LONG)xx - 15,
		(LONG)yy - 46,
		(LONG)xx + 15,
		(LONG)yy
	};
	tDis = mObjectStore->GetDistance(tUnit, this);
	tDt = dt;
	ObjectEachState();
}

void Object_Unit_Enemy_Fat::ObjectEachState()
{
	float playerX = Scene::mScene->oPlayer->GetPosition()->x();
	mTransform.SetFlip(playerX > xx);

	if (state == "fat_eat") {
		if (abs(xx - playerX) > 20) {
			mAni.Set("fat_run", 1);
		}
	}

	else if (state == "fat_run") {
		mPos.x += playerX > xx ?
			+(mPos.x.mVelocity * tDt) :
			-(mPos.x.mVelocity * tDt);
		mPos.Update(tDt);
		if (abs(xx - playerX) < 20) {
			mAni.Set("fat_eat", 1);
		}
		else if (xx < mLimit.left) {
			mPos.x = mLimit.left;
		}
		else if (xx > mLimit.right) {
			mPos.x = mLimit.right;
		}
	}
}

void Object_Unit_Enemy_Fat::ObjectGetDame(Object* pObject) {
	mHealthPoint--;
	mAni.Set("fat_hurt", 1, "fat_eat", 1);
	if (mHealthPoint <= 0) {
		mIsMarkedDelete = true;
		Scene::mScene->oObjectStore->mLost.push_back(new Object_Unit_Disappear(mPos.x() - 3, mPos.y() - 4));
	}
}