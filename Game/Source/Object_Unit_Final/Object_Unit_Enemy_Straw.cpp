#include "Object_Unit_Enemy_Straw.h"
#define mAni	mAnimation
#define mPos	mPosition
#define	mBlock	mScene->mMapBlock

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_Enemy_Straw::Object_Unit_Enemy_Straw(RECT u) : Object_Unit("CivilianEnemies") {
	mPos.x << (float)(u.left + u.right) / 2;
	mPos.y << (float)(u.top); 	
	mAni.Set("straw_stand", 1);
}

Object_Unit_Enemy_Straw::~Object_Unit_Enemy_Straw()
{
}
