#include "Object_Unit_Disappear.h"
#define mAni	mAnimation
#define mPos	mPosition
#define	mObjectStore	Scene::mScene->oObjectStore
#define tSpeedX	400
//#define tSpeedX	490

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_Disappear::Object_Unit_Disappear(float x, float y) : Object_Unit("EnemyDisappear"){
	mPos.x << x;
	mPos.y << y;
	mAni.Set("disappear", 1);
	mAutoNextFrame = true;
	mTimePerFrame = 0.03f;
}

Object_Unit_Disappear::~Object_Unit_Disappear()
{
}

void Object_Unit_Disappear::ObjectUpdateEvent(float dt)
{
	if (mAni.GetCycleIndex() == 14) {
		mIsMarkedDelete = true;
	}
}
