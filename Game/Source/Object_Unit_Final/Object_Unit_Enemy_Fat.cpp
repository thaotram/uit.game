#include "Object_Unit_Enemy_Fat.h"
#define mAni	mAnimation
#define mPos	mPosition
#define	mBlock	mScene->mMapBlock

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_Enemy_Fat::Object_Unit_Enemy_Fat(float x1, float x2, float y) : Object_Unit("Guards") {
	mPos << V2{ (x1 + x2) / 2 , y };
	mAni.Set("fat_eat", 1);

}

Object_Unit_Enemy_Fat::~Object_Unit_Enemy_Fat()
{
}
