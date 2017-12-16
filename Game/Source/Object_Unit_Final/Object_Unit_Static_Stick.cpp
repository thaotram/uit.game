#include "Object_Unit_Static_Stick.h"
#define mAni	mAnimation
#define mPos	mPosition
#define	mBlock	mScene->mMapBlock

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_Static_Stick::Object_Unit_Static_Stick(RECT u) : Object_Unit("Stick") {
	mPos.x << (float)(u.left);
	mPos.y << (float)(u.top);
	mAni.Set("stick", 1);
	mTimePerFrame = 0.03f;
	mAutoNextFrame = false;
}

Object_Unit_Static_Stick::~Object_Unit_Static_Stick(){
}
