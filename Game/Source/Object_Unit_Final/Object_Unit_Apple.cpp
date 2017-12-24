#include "Object_Unit_Apple.h"
#define mAni mAnimation
#define mPos mPosition
#define mObjectStore Scene::mScene->oObjectStore
#define tSpeedX 500
//#define tSpeedX	490

#define xx mPos.x()
#define yy mPos.y()

//# Quả táo dùng để ném đi
Object_Unit_Apple::Object_Unit_Apple(float x, float y, bool isFlip)
    : Object_Unit("Aladdin") {
    mPos << V2{x, y};
    mAni.Set("apple", 2);
    mTimePerFrame = 0.03f;
    mAutoNextFrame = false;
    mIsMakeDamage = false;
    mFlip = isFlip;
    Scene::mScene->mApple = max(Scene::mScene->mApple - 1, 0);
    mParty = Friend;
}

void Object_Unit_Apple::ObjectUpdateEvent(float dt) {
    tUnit = tUnitDamage =
        RECT{(LONG)xx - 4, (LONG)yy - 7, (LONG)xx + 3, (LONG)yy};
    tDis = mObjectStore->GetDistance(tUnit, this);
    Scene::mScene->oObjectStore->ObjectCheckCollisionWithEnemy(this);
    if (!tDis.bottom || !tDis.left || !tDis.right || mIsMakeDamage) {
        mAutoNextFrame = true;
    }
    if (!mAutoNextFrame) {
        mPos.x += mFlip ? -min(tSpeedX * dt, tDis.left)
                        : +min(tSpeedX * dt, tDis.right);
        mPos.y = yy + tDis.bottom;
        mPos.Update(dt);
    } else {
        if (mAni.GetCycleIndex() == 8) {
            mIsMarkedDelete = true;
        }
    }
}