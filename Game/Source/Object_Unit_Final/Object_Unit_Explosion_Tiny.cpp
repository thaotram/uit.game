#include "Object_Unit_Explosion_Tiny.h"
#define mAni	mAnimation
#define mPos	mPosition
#define	mObjectStore	Scene::mScene->oObjectStore
#define tSpeedX	400
//#define tSpeedX	490

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_Explosion_Tiny::Object_Unit_Explosion_Tiny(float x, float y) : Object_Unit("BossJafar") {
	mPos.x << x;
	mPos.y << y;
	mAni.Set("explosive", 1);
	mAutoNextFrame = true;
	mTimePerFrame = 0.02f;
}

Object_Unit_Explosion_Tiny::~Object_Unit_Explosion_Tiny()
{
}

void Object_Unit_Explosion_Tiny::ObjectUpdateEvent(float dt)
{
	if (mAni.GetCycleIndex() == 4)
	{
		mIsMarkedDelete = true;
	}
}
