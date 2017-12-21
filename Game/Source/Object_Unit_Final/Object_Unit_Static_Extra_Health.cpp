#include "Object_Unit_Static_Extra_Health.h"
#define mAni	mAnimation
#define mPos	mPosition
Object_Unit_Static_Extra_Health::Object_Unit_Static_Extra_Health(RECT u) : Object_Unit("Item") {
	mPos.x << (float)(u.left);
	mPos.y << (float)(u.top);
	mAni.Set("extrahealth", 1);
	mTimePerFrame = 0.03f;
	mAutoNextFrame = true;
	tUnit = GetBound();
}

void Object_Unit_Static_Extra_Health::ObjectUpdateEvent(float dt)
{

}

void Object_Unit_Static_Extra_Health::ObjectIntersect(Object * pObject)
{
	Scene::mScene->mScore += 150;
	Scene::mScene->mBlood = min(Scene::mScene->mBlood + 1,8);
	mIsMarkedDelete = true;
}
