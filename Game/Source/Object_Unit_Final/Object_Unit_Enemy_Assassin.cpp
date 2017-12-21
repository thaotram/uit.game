#include "Object_Unit_Enemy_Assassin.h"
#include "../Object_Unit_Final/Object_Unit_Jar_Copper.h"

#define mAni			mAnimation
#define mPos			mPosition
#define	mObjectStore	Scene::mScene->oObjectStore

#define xx mPos.x()
#define yy mPos.y()
#define state mAni.GetState()

Object_Unit_Enemy_Assassin::Object_Unit_Enemy_Assassin(RECT u)
	: Object_Unit("CivilianEnemies") {
	mPos.x << (float)(u.left + u.right) / 2;
	mPos.y << (float)(u.top) + 22;
	mAni.Set("assassin", 11);
	mHealthPoint = 1;
	mParty = Enemy;
}

void Object_Unit_Enemy_Assassin::ObjectUpdateEvent(float dt) {
	tUnit = GetBound();
	ObjectEachState();
}

void Object_Unit_Enemy_Assassin::ObjectEachState() {
	float playerX = Scene::mScene->oPlayer->GetPosition()->x();
	if (mAni.GetCycleIndex() == 1) {
		mIsThrow = false;
	}
	else if (mAni.GetCycleIndex() == 8 && !mIsThrow) {
		Scene::mScene->oObjectStore->mLost.push_back(
			new Object_Unit_Jar_Copper(xx + 26, yy + 13)
		);
		mIsThrow = true;
	}
	else if (mAni.GetCycleIndex() == 11 && abs(xx - playerX) < 50) {
		mAni.SetCycleIndex(1);
	}
}

void Object_Unit_Enemy_Assassin::ObjectGetDame(Object * pObject) {
	mHealthPoint--;
	if (mHealthPoint <= 0) {
		mIsMarkedDelete = true;
		Scene::mScene->oObjectStore->mLost.push_back(new Object_Unit_Disappear(mPos.x() - 3, mPos.y() - 4));
	}
}