#include "Object_Unit_Enemy_Jarfar.h"
#define mAni mAnimation
#define mPos mPosition
#define mObjectStore Scene::mScene->oObjectStore
#define isFlip (mTransform.GetFlip())

#define xx mPos.x()
#define yy mPos.y()

#define state	mAni.GetState()

Object_Unit_Enemy_Jarfar::Object_Unit_Enemy_Jarfar(float x, float y)
    : Object_Unit("BossJafar") {
    mPos.x << x;
    mPos.y << y;
    mAni.Set("jafar_human", 1);
    mParty = Enemy;
}

Object_Unit_Enemy_Jarfar::~Object_Unit_Enemy_Jarfar() {}

void Object_Unit_Enemy_Jarfar::ObjectUpdateEvent(float dt) {
    tUnit = RECT{(LONG)xx - 8, (LONG)yy - 58, (LONG)xx + 8, (LONG)yy};
    ObjectEachState();
}

void Object_Unit_Enemy_Jarfar::ObjectEachState() {
    float playerX = Scene::mScene->oPlayer->GetPosition()->x();
    float distanceX = abs(xx - playerX);
    mTransform.SetFlip(playerX < xx);

	if(state == "jafar_human"){
		if(
			distanceX > 10 && 
			mAni.GetCycleIndex() != 5 &&
			mAni.GetCycleIndex() != 6) {
			mAni.SetCycleIndex(1);
		}
		else if(distanceX <= 10){
			mAni.SetCycleIndex(8);
		}
	}
    // if (mAni.GetCycleIndex() == 1) {
    //     // mIsThrow = false;
    // } else if (mAni.GetCycleIndex() == 11 && !mIsThrow) {
    //     if (distanceX > 120) {
    //         Scene::mScene->oObjectStore->mLost.push_back(new Object_Unit_Knife(
    //             xx + (isFlip ? -20 : 20), yy - 65, -160, -400, isFlip));
    //     } else {
    //         Scene::mScene->oObjectStore->mLost.push_back(new Object_Unit_Knife(
    //             xx + (isFlip ? -45 : 45), yy - 30, -400, 0, isFlip));
    //     }
    //     mIsThrow = true;
    // }
}

void Object_Unit_Enemy_Jarfar::ObjectIntersect(Object* pObject) {
    // mHealthPoint--;
    // if (mHealthPoint <= 0) {
    //     mIsMarkedDelete = true;
    //     Scene::mScene->oObjectStore->mLost.push_back(
    //         new Object_Unit_Disappear(mPos.x() - 3, mPos.y() - 4));
    // }
}