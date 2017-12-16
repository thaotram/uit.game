#include "Object_Unit_Enemy_Pirates.h"
#define mAni	mAnimation
#define mPos	mPosition
#define	mObjectStore	Scene::mScene->oObjectStore

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_Enemy_Pirates::Object_Unit_Enemy_Pirates(RECT u) : Object_Unit("Guards")
{
	mPos.x << (float)(u.left + u.right) / 2;
	mPos.y << (float)(u.top); 	
	mAni.Set("pirates_defiant", 1);

}

Object_Unit_Enemy_Pirates::~Object_Unit_Enemy_Pirates()
{
}
