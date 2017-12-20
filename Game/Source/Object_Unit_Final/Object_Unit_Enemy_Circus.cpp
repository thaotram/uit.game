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
}

Object_Unit_Enemy_Circus::~Object_Unit_Enemy_Circus() {}

void Object_Unit_Enemy_Circus::ObjectUpdateEvent(float dt)
{
	ObjectEachState();
}

void Object_Unit_Enemy_Circus::ObjectEachState()
{
	if (mAni.GetCycleIndex() == 1) {
		mIsThrow = false;
	}
	else if (mAni.GetCycleIndex() == 11 && !mIsThrow) {
		Scene::mScene->oObjectStore->mLost.push_back(
			new Object_Unit_Knife(xx, yy-50, mTransform.GetFlip())
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