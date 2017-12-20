#include "Object_Unit_Savila.h"
#include "Object_Unit_NPC_Camel.h"
#define mAni	mAnimation
#define mPos	mPosition
#define	mObjectStore	Scene::mScene->oObjectStore
#define tSpeedX	400
#define xx mPos.x()
#define yy mPos.y()

Object_Unit_Savila::Object_Unit_Savila(float x, float y) : Object_Unit("Camel")
{
	mPos << V2{ x,y };
	mAni.Set("savila", 1);
	mTimePerFrame = 0.03f;
	mAutoNextFrame = false;
	mParty = Friend;
}

Object_Unit_Savila::~Object_Unit_Savila()
{
}

void Object_Unit_Savila::ObjectUpdateEvent(float dt)
{
	tUnit = RECT{
		(LONG)xx,
		(LONG)yy,
		(LONG)xx,
		(LONG)yy
	};
	tDis = mObjectStore->GetDistance(tUnit, this);

	mPos.x += tSpeedX*dt;
	mPos.x.Update(dt);
	//if (tDis.right <= (xCamel + 42 + 20)) {
	//}
	//else {
	//	if (mAni.GetCycleIndex() == 8) {
	//		mIsMarkedDelete = true;
	//	}
	//}
}