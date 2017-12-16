#include "Object_Unit_Static_Stick.h"
#define mAni	mAnimation
#define mPos	mPosition
#define	mBlock	mScene->mMapBlock

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_Static_Stick::Object_Unit_Static_Stick(float x, float y) : Object_Unit("Stick") {
	mPos << V2{ x , y };
	mAni.Set("stick", 1);
}

Object_Unit_Static_Stick::~Object_Unit_Static_Stick()
{
}
