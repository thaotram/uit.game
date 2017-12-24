#include "Object_Unit_Bullet_Star.h"
#include "Object_Unit_NPC_Camel.h"
#define mAni mAnimation
#define mPos mPosition
#define mObjectStore Scene::mScene->oObjectStore
#define tSpeedX 400
#define xx mPos.x()
#define yy mPos.y()

Object_Unit_Bullet_Star::Object_Unit_Bullet_Star(float x, float y)
    : Object_Unit("BossJafar") {
    mPos << V2{x, y};
    mPos.x.mType = mPos.y.mType = bytime;
    mAni.Set("bullet_star", 1);

    mAutoNextFrame = true;
    mParty = Enemy;
}

void Object_Unit_Bullet_Star::ObjectUpdateEvent(float dt) {
    tUnit = RECT{(LONG)xx, (LONG)yy, (LONG)xx, (LONG)yy};
    tDis = mObjectStore->GetDistance(tUnit, this);
    tUnitDamage = RECT{(LONG)xx - 14, (LONG)yy - 24, (LONG)xx + 14, (LONG)yy};
    Scene::mScene->oObjectStore->ObjectCheckCollisionWithPlayer(this);
    auto pos = Scene::mScene->oPlayer->GetPosition();
    if (!tDis.bottom || !tDis.left || !tDis.right || mIsMakeDamage) {
        mIsMarkedDelete = true;
    }

    mPos.x = pos->x();
    mPos.y = pos->y();
    mPos.Update(dt);
}