#include "Object_Unit_Knife.h"
#define mAni	mAnimation
#define mPos	mPosition
#define	mObjectStore	Scene::mScene->oObjectStore
#define tSpeedX	200

#define xx mPos.x()
#define yy mPos.y()

//# Ném dao của Fat & Circus

Object_Unit_Knife::Object_Unit_Knife(float x, float y, bool isFlip) : Object_Unit("Guards"){
	mPos << V2{ x, y };
	mAni.Set("fat_knife", 1);
	mTimePerFrame = 0.03f;
	mAutoNextFrame = true;
	mIsCollision = false;
	mFlip = isFlip;
	mPos.y.mVelocity = -500;
}

Object_Unit_Knife::~Object_Unit_Knife()
{
}

void Object_Unit_Knife::ObjectUpdateEvent(float dt)
{
	tUnit=
		RECT{
			(LONG)xx,
			(LONG)yy,
			(LONG)xx,
			(LONG)yy
	};
	tDis = mObjectStore->GetDistance(tUnit, this);
	//Scene::mScene->oObjectStore->ObjectCheckCollision(this);
	
	if (tDis.bottom == 0 || tDis.left == 0 || tDis.right == 0) {
		mIsMarkedDelete = true;
	Scene::mScene->oObjectStore->mLost.push_back(
		new Object_Unit_Explosion_Tiny(mPos.x(), mPos.y())
	);
	}
	else {
		mPos.x +=
			mFlip ?
			-min(tSpeedX * dt, tDis.left) :
			+min(tSpeedX * dt, tDis.right);
		mPos.y = yy + tDis.bottom;
		mPos.Update(dt);
	}


	//if (!mAutoNextFrame) {
	//	mPos.y = yy + tDis.bottom;
	//	mPos.Update(dt);
	//}
	//else {
	//	if (mAni.GetCycleIndex() == 8) {
	//		mIsMarkedDelete = true;
	//	}
	//}

}
void Object_Unit_Knife::ObjectIntersect(Object* pObject) {
	mAutoNextFrame = true;
	mIsMarkedDelete = true;
	// Scene::mScene->Add(Scene::mScene->itPlayer, new
	// Object_Unit_Explosion_Big(mPos.x()+20,mPos.y()));
}

