#include "Object_Unit_Enemy_Straw.h"
#define mAni	mAnimation
#define mPos	mPosition
#define	mObjectStore	Scene::mScene->oObjectStore
#define isFlip			(mTransform.GetFlip())

#define xx mPos.x()
#define yy mPos.y()

#define state	mAni.GetState()

Object_Unit_Enemy_Straw::Object_Unit_Enemy_Straw(RECT u) : Object_Unit("CivilianEnemies") {
	mPos.x << (float)(u.left + u.right) / 2;
	mPos.y << (float)(u.top);
	mAni.Set("straw_stand", 1);
}

Object_Unit_Enemy_Straw::~Object_Unit_Enemy_Straw()
{
}

void Object_Unit_Enemy_Straw::ObjectUpdateEvent(float dt)
{
}

void Object_Unit_Enemy_Straw::ObjectEachState()
{
	if (state == "") {
		mAni.Set("straw_stand", 1);
	}
	else if (state == "straw_hit") {
		if (mAni.GetCycleIndex() == 4) {
			tUnitDamage = RECT{
				(LONG)((isFlip) ? (xx - 42) : (xx + 5)),
				(LONG)(yy - 36),
				(LONG)((isFlip) ? (xx - 5) : (xx + 42)),
				(LONG)(yy - 24)
			};
		}
	}
}

void Object_Unit_Enemy_Straw::ObjectGetDame(Object * pObject)
{
	mHealthPoint--;
	if (mHealthPoint <= 0) {
		mIsMarkedDelete = true;
		Scene::mScene->oObjectStore->mLost.push_back(new Object_Unit_Disappear(mPos.x() - 3, mPos.y() - 4));
	}
}
