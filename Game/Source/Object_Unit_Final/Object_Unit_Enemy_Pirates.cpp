#include "Object_Unit_Enemy_Pirates.h"
#define mAni	mAnimation
#define mPos	mPosition
#define	mObjectStore	Scene::mScene->oObjectStore
#define isFlip			(mTransform.GetFlip())

#define xx mPos.x()
#define yy mPos.y()

#define state	mAni.GetState()

Object_Unit_Enemy_Pirates::Object_Unit_Enemy_Pirates(RECT u) : Object_Unit("Guards")
{
	mPos.x << (float)(u.left + u.right) / 2;
	mPos.y << (float)(u.top);
	mAni.Set("pirates_defiant", 1);
	mParty = Enemy;
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
	ObjectEachState();
}

void Object_Unit_Enemy_Pirates::ObjectEachState()
{
	if (state == "") {
		mAni.Set("pirates_defiant", 1);
	}
	else if (state == "pirates_poke") {
		if (mAni.GetCycleIndex() == 6) {
			tUnitDamage = RECT{
				(LONG)((isFlip) ? (xx + 75) : (xx - 18)),
				(LONG)(yy - 23),
				(LONG)((isFlip) ? (xx + 18) : (xx - 75)),
				(LONG)(yy - 10)
			};
		}
	}
	else if (state == "pirates_cut") {
		if (mAni.GetCycleIndex() == 4) {
			tUnitDamage = RECT{
				(LONG)((isFlip) ? (xx - 27) : (xx - 83)),
				(LONG)(yy - 52),
				(LONG)((isFlip) ? (xx + 83) : (xx + 27)),
				(LONG)(yy - 25)
			};
		}
	}
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
