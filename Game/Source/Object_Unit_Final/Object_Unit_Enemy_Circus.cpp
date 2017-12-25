#pragma once
#include "Object_Unit_Enemy_Circus.h"
#include "Object_Unit_Aladdin.h"

#define mAni	mAnimation
#define mPos	mPosition
#define	mObjectStore	Scene::mScene->oObjectStore
#define isFlip			(mTransform.GetFlip())

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_Enemy_Circus::Object_Unit_Enemy_Circus(RECT u) : Object_Unit("CivilianEnemies") {
	mPos.x << (float)(u.left + u.right) / 2;
	mPos.y << (float)(u.top);
	mAni.Set("circus", 1);
	mParty = Enemy;
}

Object_Unit_Enemy_Circus::~Object_Unit_Enemy_Circus() {}

void Object_Unit_Enemy_Circus::ObjectUpdateEvent(float dt)
{
	tUnit = RECT{
		(LONG)xx - 8,
		(LONG)yy - 58,
		(LONG)xx + 8,
		(LONG)yy
	};
	ObjectEachState();
}

void Object_Unit_Enemy_Circus::ObjectEachState()
{
	float playerX = Scene::mScene->oPlayer->GetPosition()->x();
	mTransform.SetFlip(playerX < xx);
	float distanceX = abs(xx - playerX);

	if (mAni.GetCycleIndex() == 1) {
		mIsThrow = false;
	}
	else if (mAni.GetCycleIndex() == 11 && !mIsThrow) {
		if (distanceX > 120) {
			Scene::mScene->oObjectStore->mLost.push_back(
				new Object_Unit_Knife(xx + (isFlip ? -20 : 20), yy - 65, -160, -400, isFlip)
			);
		}
		else {
			Scene::mScene->oObjectStore->mLost.push_back(
				new Object_Unit_Knife(xx + (isFlip ? -45 : 45), yy - 30, -400, 0, isFlip)
			);
		}
		mIsThrow = true;
	}
}

void Object_Unit_Enemy_Circus::ObjectIntersect(Object * pObject)
{
	mHealthPoint--;
	if (mHealthPoint <= 0) {
		mIsMarkedDelete = true;
		Scene::mScene->oObjectStore->mLost.push_back(new Object_Unit_Disappear(mPos.x() - 3, mPos.y() - 4));
	}
}