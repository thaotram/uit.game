#include "Object_Unit_Explosion_Big.h"
#define mAni mAnimation
#define mPos mPosition
#define mObjectStore Scene::mScene->oObjectStore
#define tSpeedX 400
//#define tSpeedX	490

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_Explosion_Big::Object_Unit_Explosion_Big(float x, float y)
    : Object_Unit("EnemyExplosions") {
    mPos.x << x;
    mPos.y << y;
    mAni.Set("blue_smoke", 1);
    mAutoNextFrame = true;
    mTimePerFrame = 0.02f;
    mParty = Friend;
    tUnitDamage =
        RECT{(LONG)x - 100, (LONG)y - 100, (LONG)x + 100, (LONG)y + 20};
}

void Object_Unit_Explosion_Big::ObjectUpdateEvent(float dt) {
    mIsMakeDamage = false;
    mObjectStore->ObjectCheckCollisionWithEnemy(this);
    if (mAni.GetCycleIndex() == 16) {
        mIsMarkedDelete = true;
    }
}
