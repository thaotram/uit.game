#include "Object_Unit_Enemy_Assassin.h"
#define mAni	mAnimation
#define mPos	mPosition
#define	mObjectStore	Scene::mScene->oObjectStore

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_Enemy_Assassin::Object_Unit_Enemy_Assassin(RECT u) : Object_Unit("CivilianEnemies") {
	mPos.x << (float)(u.left + u.right) / 2;
	mPos.y << (float)(u.top) + 22;
	mAni.Set("assassin", 1);
}

Object_Unit_Enemy_Assassin::~Object_Unit_Enemy_Assassin() {
}

void Object_Unit_Enemy_Assassin::ObjectUpdateEvent(float dt)
{
}

void Object_Unit_Enemy_Assassin::ObjectEachState()
{
}

void Object_Unit_Enemy_Assassin::ObjectGetDame(Object * pObject)
{
	mHealthPoint--;
	if (mHealthPoint <= 0) {
		mIsMarkedDelete = true;
	}
}
