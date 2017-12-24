#include "Object_Unit_Bullet_Star.h"
#include "../Object_Unit_Final/Object_Unit_Explosion_Tiny.h"
#define mAni mAnimation
#define mPos mPosition
#define mObjectStore Scene::mScene->oObjectStore
#define tSpeedX 400
#define xx mPos.x()
#define yy mPos.y()

Object_Unit_Bullet_Star::Object_Unit_Bullet_Star(float x, float y)
    : Object_Unit("BossJafar") {
    mPos << V2{x, y};
    mPos.x.mType = mPos.y.mType = pull;

    mAni.Set("bullet_star", rand() % 3 + 1);

    mAutoNextFrame = true;
    mParty = Enemy;
}

void Object_Unit_Bullet_Star::ObjectUpdateEvent(float dt) {
    tUnit = RECT{(LONG)xx, (LONG)yy, (LONG)xx, (LONG)yy};
    tDis = mObjectStore->GetDistance(tUnit, this);
    tUnitDamage = RECT{(LONG)xx - 14, (LONG)yy - 14, (LONG)xx + 14, (LONG)yy};
    Scene::mScene->oObjectStore->ObjectCheckCollisionWithPlayerBulletStar(this);
    auto pos = Scene::mScene->oPlayer->GetPosition();

    if (mIsMakeDamage) {
        mIsMarkedDelete = true;
        Scene::mScene->oObjectStore->mLost.push_back(
            new Object_Unit_Explosion_Tiny(xx, yy));
    }

    mPos.x = pos->x();
    mPos.y = pos->y() - 30;
    mPos.Update(dt);
}