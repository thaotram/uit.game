#include "Object_Unit_Enemy_Thin.h"
#define mAni			mAnimation
#define mPos			mPosition
#define	mObjectStore	Scene::mScene->oObjectStore
#define isFlip			(mTransform.GetFlip())

#define xx mPos.x()
#define yy mPos.y()

#define state	mAni.GetState()

Object_Unit_Enemy_Thin::Object_Unit_Enemy_Thin(RECT u) : Object_Unit("Guards") {
	mPos.x << (float)(u.left + u.right) / 2;
	mPos.y << (float)(u.top);
	mAni.Set("thin_hit", 1);
	mHealthPoint = 2;
	mParty = Enemy;
}

Object_Unit_Enemy_Thin::~Object_Unit_Enemy_Thin() {}

void Object_Unit_Enemy_Thin::ObjectUpdateEvent(float dt) {
	if (mHealthPoint == 0) {
		mIsMarkedDelete = true;
	}
	ObjectEachState();

	tUnit = RECT{
		(LONG)xx - 15,
		(LONG)yy - 60,
		(LONG)xx + 15,
		(LONG)yy
	};
}

void Object_Unit_Enemy_Thin::ObjectEachState() {
	if (state == "") {
		mAni.Set("thin_stand", 1);
	}
	else if (state == "thin_run") {
		mAutoNextFrame = true;
	}
	else if (state == "thin_hit") {
		if (mAni.GetCycleIndex() == 3) {
			tUnitDamage = RECT{
				(LONG)((isFlip) ? (xx + 77) : (xx - 26)),
				(LONG)(yy - 46),
				(LONG)((isFlip) ? (xx + 26) : (xx - 77)),
				(LONG)(yy - 18)
			};
		}
	}
}

void Object_Unit_Enemy_Thin::ObjectGetDame(Object * pObject)
{
	mHealthPoint--;
	mAni.Set("thin_hurt", 1, "thin_stand", 1);
	if (mHealthPoint <= 0) {
		mIsMarkedDelete = true;
		Scene::mScene->oObjectStore->mLost.push_back(new Object_Unit_Disappear(mPos.x() - 3, mPos.y() - 4));
	}
}
