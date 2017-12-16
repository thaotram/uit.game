#include "Object_Unit_Explosion_Small.h"
#define mAni	mAnimation
#define mPos	mPosition
#define	mObjectStore	Scene::mScene->oObjectStore
#define tSpeedX	400
//#define tSpeedX	490

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_Explosion_Small::Object_Unit_Explosion_Small(float x, float y) : Object_Unit("EnemyExplosions") {
}

Object_Unit_Explosion_Small::~Object_Unit_Explosion_Small()
{
}

void Object_Unit_Explosion_Small::ObjectUpdateEvent(float dt)
{
}
