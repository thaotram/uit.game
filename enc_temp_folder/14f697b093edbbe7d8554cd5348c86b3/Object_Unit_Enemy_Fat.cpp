#include "Object_Unit_Enemy_Fat.h"
#define mAni	mAnimation
#define mPos	mPosition
#define	mBlock	mScene->mMapBlock

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_Enemy_Fat::Object_Unit_Enemy_Fat(RECT u) : Object_Unit("Guards") {
	mPos.x << (float)(u.left + u.right) / 2;
	mPos.y << (float)(u.bottom); 	
	mAni.Set("fat_eat", 1);

}

Object_Unit_Enemy_Fat::~Object_Unit_Enemy_Fat()
{
}
