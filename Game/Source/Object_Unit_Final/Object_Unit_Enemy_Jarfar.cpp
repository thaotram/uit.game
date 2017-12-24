#include "Object_Unit_Enemy_Jarfar.h"

#define mAni mAnimation
#define mPos mPosition
#define mObjectStore Scene::mScene->oObjectStore
#define isFlip (mTransform.GetFlip())

#define xx mPos.x()
#define yy mPos.y()

#define state mAni.GetState()

Object_Unit_Enemy_Jarfar::Object_Unit_Enemy_Jarfar(float x, float y)
    : Object_Unit("BossJafar") {
    mPos.x << x;
    mPos.y << y;
    mAni.Set("jafar_human", 2);
    mParty = Enemy;
    mAutoNextFrame = false;
    mHealthPoint = 10;

	mIsCash = false;
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

    const int range = 50;
    if (state == "jafar_human") {
        if (distanceX <= range) {
            mAutoNextFrame = false;
            mAni.SetCycleIndex(1);
        } else {
            // Đủ tầm cho nó cash phép
            if (!mAutoNextFrame) {
                mAutoNextFrame = true;
                mAni.SetCycleIndex(2);
            }
        }
        int index = mAni.GetCycleIndex();
		if (index == 4 || index == 6 || index == 8 || index == 10) {
			mIsCash = false;
		} else if ((index == 5 || index == 7 || index == 9) && !mIsCash) {
			mIsCash = true; 
            Scene::mScene->oObjectStore->mLost.push_back(
				new Object_Unit_Bullet_Star(xx + 70 * (isFlip ? - 1 : +1), yy - 40)
			);
        }
    }
}

void Object_Unit_Enemy_Jarfar::ObjectIntersect(Object* pObject) {
    // mHealthPoint--;
    // if (mHealthPoint <= 0) {
    //     mIsMarkedDelete = true;
    //     Scene::mScene->oObjectStore->mLost.push_back(
    //         new Object_Unit_Disappear(mPos.x() - 3, mPos.y() - 4));
    // }
}