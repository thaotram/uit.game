#include "Object_Unit_Fire.h"
#include "Object_Unit_Aladdin.h"
#define mAni	mAnimation
#define mPos	mPosition
#define	mObjectStore	Scene::mScene->oObjectStore

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_Fire::Object_Unit_Fire(float x, float y) : Object_Unit("BossJafar") {
	mPos.x << x;
	mPos.y << y;
	mAni.Set("fire", 1);
	mTimePerFrame = 0.03f;
	mAutoNextFrame = true;
	mTime = 0;
}

Object_Unit_Fire::~Object_Unit_Fire() {}

void Object_Unit_Fire::ObjectUpdateEvent(float dt) {
	mTime += dt;
	if (mTime >= 0.8f) {
		mIsMarkedDelete = true;
	}
}