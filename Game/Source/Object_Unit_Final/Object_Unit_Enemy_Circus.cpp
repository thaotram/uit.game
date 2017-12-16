#include "Object_Unit_Enemy_Circus.h"
#define mAni	mAnimation
#define mPos	mPosition
#define	mBlock	mScene->mMapBlock

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_Enemy_Circus::Object_Unit_Enemy_Circus(float x1, float x2, float y) : Object_Unit("CivilianEnemies") {
	mPos << V2{ (x1 + x2) / 2 , y };
	mAni.Set("circus", 1);
}

Object_Unit_Enemy_Circus::~Object_Unit_Enemy_Circus()
{
}
