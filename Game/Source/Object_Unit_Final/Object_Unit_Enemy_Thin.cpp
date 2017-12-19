#include "Object_Unit_Enemy_Thin.h"
#define mAni			mAnimation
#define mPos			mPosition
#define	mObjectStore	Scene::mScene->oObjectStore
#define isFlip			(mTransform.GetFlip())

#define xx mPos.x()
#define yy mPos.y()

#define state	mAni.GetState()

Object_Unit_Enemy_Thin::Object_Unit_Enemy_Thin(RECT u) : Object_Unit("BossJafar") {
	mPos.x << (float)(u.left + u.right) / 2;
	mPos.y << (float)(u.top);
	mAni.Set("jafar_human", 1);
	mHealthPoint = 2;
}
//Object_Unit_Enemy_Thin::Object_Unit_Enemy_Thin(RECT u) : Object_Unit("Guards") {
//	mPos.x << (float)(u.left + u.right) / 2;
//	mPos.y << (float)(u.top);
//	mAni.Set("thin_stand", 1);
//	mHealthPoint = 2;
//}

Object_Unit_Enemy_Thin::~Object_Unit_Enemy_Thin() {}

void Object_Unit_Enemy_Thin::ObjectUpdateEvent(float dt) {
	if (mHealthPoint == 0) {
		mIsMarkedDelete = true;
	}
}

void Object_Unit_Enemy_Thin::ObjectEachState() {
	if (state == "") {
		mAni.Set("thin_stand", 1);
	}
	else if (state == " thin_run") {
		mAutoNextFrame = true;
	}
	else if (state == "thin_hit") {
		if (mAni.GetCycleIndex() == 3) {
			tUnitDamage = RECT{
				(LONG)((isFlip) ? (xx - 63) : (xx + 16)),
				(LONG)(yy - 68),
				(LONG)((isFlip) ? (xx - 16) : (xx + 63)),
				(LONG)(yy - 6)
			};
		}
		if (mAni.GetCycleIndex() == 4) {
			tUnitDamage = RECT{
				(LONG)((isFlip) ? (xx - 63) : (xx + 16)),
				(LONG)(yy - 68),
				(LONG)((isFlip) ? (xx - 16) : (xx + 63)),
				(LONG)(yy - 6)
			};
		}
		if (mAni.GetCycleIndex() == 5) {
			tUnitDamage = RECT{
				(LONG)((isFlip) ? (xx - 63) : (xx + 16)),
				(LONG)(yy - 68),
				(LONG)((isFlip) ? (xx - 16) : (xx + 63)),
				(LONG)(yy - 6)
			};
		}
	}
}