#include "Object_Unit_Enemy_Circus.h"
#define mAni	mAnimation
#define mPos	mPosition
#define	mObjectStore	mScene->oObjectStore

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_Enemy_Circus::Object_Unit_Enemy_Circus(RECT u) : Object_Unit("CivilianEnemies") {
	mPos.x << (float)(u.left + u.right) / 2;
	mPos.y << (float)(u.top); 	
	mAni.Set("circus", 1);
}

Object_Unit_Enemy_Circus::~Object_Unit_Enemy_Circus()
{
}
