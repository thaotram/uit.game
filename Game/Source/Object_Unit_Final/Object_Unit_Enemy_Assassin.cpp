#include "Object_Unit_Enemy_Assassin.h"
#define mAni	mAnimation
#define mPos	mPosition
#define	mBlock	mScene->mMapBlock

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_Enemy_Assassin::Object_Unit_Enemy_Assassin(RECT u) : Object_Unit("CivilianEnemies") {
	mPos.x << (float)(u.left + u.right) / 2;
	mPos.y << (float)(u.top) + 22; 	
	mAni.Set("assassin", 1);
}

Object_Unit_Enemy_Assassin::~Object_Unit_Enemy_Assassin(){
}
