#include "Object_Unit_Enemy_Thin.h"
#define mAni			mAnimation
#define mPos			mPosition
#define	mObjectStore	mScene->oObjectStore

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_Enemy_Thin::Object_Unit_Enemy_Thin(RECT u) : Object_Unit("Guards") {
	mPos.x << (float)(u.left + u.right) / 2;
	mPos.y << (float)(u.top);
	mAni.Set("thin_stand", 1);
	mHealthPoint = 2;
}

Object_Unit_Enemy_Thin::~Object_Unit_Enemy_Thin() {}

void Object_Unit_Enemy_Thin::ObjectUpdateEvent(float dt){
	if (mHealthPoint == 0) {
		mIsMarkedDelete = true;
	}
}
