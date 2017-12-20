#include "Object_Unit_Explosion.h"
#define mAni	mAnimation
#define mPos	mPosition
#define	mObjectStore	Scene::mScene->oObjectStore
#define tSpeedX	400
//#define tSpeedX	490

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_Explosion::Object_Unit_Explosion(float x, float y) : Object_Unit("EnemyExplosions") {
	mPos.x << x;
	mPos.y << y;
	mAni.Set("blue_smoke", 1);
	mAutoNextFrame = true;
	mTimePerFrame = 0.02f;
}

Object_Unit_Explosion::~Object_Unit_Explosion()
{
}

void Object_Unit_Explosion::ObjectUpdateEvent(float dt)
{
	if (mAni.GetCycleIndex() == 16)
	{
		mIsMarkedDelete = true;
	}
}
