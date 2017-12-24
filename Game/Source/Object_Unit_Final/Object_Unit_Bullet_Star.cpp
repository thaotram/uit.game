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
	mPos.x.mType = mPos.y.mType = gravity;
    mAni.Set("bullet_star", 1);
    mAutoNextFrame = true;
    mParty = Enemy;
}

void Object_Unit_Bullet_Star::ObjectUpdateEvent(float dt) {
    tUnit = RECT{(LONG)xx, (LONG)yy, (LONG)xx + 6, (LONG)yy + 5};
    tDis = mObjectStore->GetDistance(tUnit, this);
	//tUnitDamage = RECT{ 0,0,0,0 };
    //Scene::mScene->oObjectStore->ObjectCheckCollisionWithPlayer(this);
	auto pos = Scene::mScene->oPlayer->GetPosition();

	if (tDis.right == 0) mIsMarkedDelete = true;
    
	mPos.x = pos->x();
	mPos.y = pos->y();
    mPos.Update(dt);
}