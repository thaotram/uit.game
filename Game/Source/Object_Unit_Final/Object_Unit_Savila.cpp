#include "Object_Unit_Savila.h"
#include "Object_Unit_NPC_Camel.h"
#define mAni mAnimation
#define mPos mPosition
#define mObjectStore Scene::mScene->oObjectStore
#define tSpeedX 400
#define xx mPos.x()
#define yy mPos.y()

Object_Unit_Savila::Object_Unit_Savila(float x, float y)
    : Object_Unit("Camel") {
    mPos << V2{x, y};
    mAni.Set("savila", 1);
    mAutoNextFrame = false;
    mParty = Friend;
}

void Object_Unit_Savila::ObjectUpdateEvent(float dt) {
    tUnit = tUnitDamage = RECT{(LONG)xx, (LONG)yy, (LONG)xx, (LONG)yy};
    tDis = mObjectStore->GetDistance(tUnit, this);
    Scene::mScene->oObjectStore->Collision_Player_Enemy(this);
    if (tDis.right == 0 || mIsMakeDamage) mIsMarkedDelete = true;

    mPos.x += min(tSpeedX * dt, tDis.right);
    mPos.x.Update(dt);
}