#include "Object_Unit_Enemy_Circus.h"
#define mAni	mAnimation
#define mPos	mPosition
#define	mObjectStore	Scene::mScene->oObjectStore

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
	if (mAni.GetCycleIndex() == 1) {
		mIsThrow = false;
	}
	else if (mAni.GetCycleIndex() == 11 && !mIsThrow) {
		Scene::mScene->oObjectStore->mLost.push_back(
			//new Object_Unit_Knife(xx, yy-50, mTransform.GetFlip())
			new Object_Unit_Knife(xx, yy - 50, true)
		);
		mIsThrow = true;
	}
}

void Object_Unit_Enemy_Circus::ObjectGetDame(Object * pObject)
{
	mHealthPoint--;
	if (mHealthPoint <= 0) {
		mIsMarkedDelete = true;
		Scene::mScene->oObjectStore->mLost.push_back(new Object_Unit_Disappear(mPos.x() - 3, mPos.y() - 4));
	}
}