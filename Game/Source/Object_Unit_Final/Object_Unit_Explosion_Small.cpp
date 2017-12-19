#include "Object_Unit_Explosion_Small.h"
#define mAni	mAnimation
#define mPos	mPosition
#define	mObjectStore	Scene::mScene->oObjectStore
#define tSpeedX	400
//#define tSpeedX	490

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_Explosion_Small::Object_Unit_Explosion_Small(float x, float y) : Object_Unit("EnemyExplosions") {
	mPos.x << x;
	mPos.y << y;
	mAni.Set("firework", 1);
	mAutoNextFrame = true;
	mTimePerFrame = 0.02f;
}

Object_Unit_Explosion_Small::~Object_Unit_Explosion_Small()
{
}

void Object_Unit_Explosion_Small::ObjectUpdateEvent(float dt)
{
	if (mAni.GetCycleIndex() == 21) {
		mIsMarkedDelete = true;
	}
}
