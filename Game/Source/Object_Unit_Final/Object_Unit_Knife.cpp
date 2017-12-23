#include "Object_Unit_Knife.h"
#define mAni	mAnimation
#define mPos	mPosition
#define	mObjectStore	Scene::mScene->oObjectStore

#define xx mPos.x()
#define yy mPos.y()

//# Ném dao của Fat & Circus

Object_Unit_Knife::Object_Unit_Knife(float x, float y, float pVelocityX, float pVelocityY, bool isFlip) : Object_Unit("Guards"){
	mPos << V2{ x, y };
	mAni.Set("fat_knife", 1);
	mTimePerFrame = 0.03f;
	mAutoNextFrame = true;
	mIsCollision = false;
	mIsMakeDamage = false;
	mFlip = !isFlip;

	mPos.x.mVelocity = pVelocityX;	// = 400
	mPos.y.mVelocity = pVelocityY; 	// = -500;
	mParty = Enemy;
}

void Object_Unit_Knife::ObjectUpdateEvent(float dt) {
	tUnit = RECT{
		(LONG)xx-5,
		(LONG)yy-15,
		(LONG)xx+5,
		(LONG)yy+15
	};
	tDis = mObjectStore->GetDistance(tUnit, this);
	tUnitDamage = GetBound();
	Scene::mScene->oObjectStore->ObjectCheckCollisionWithPlayer(this);
	
	if (!tDis.bottom || !tDis.left || !tDis.right || mIsMakeDamage) {
		mIsMarkedDelete = true;
		Scene::mScene->oObjectStore->mLost.push_back(
			new Object_Unit_Explosion_Tiny(mPos.x(), mPos.y())
		);
	}
	else {
		mPos.x +=
			mFlip ?
			-min(mPos.x.mVelocity * dt, tDis.left) :
			+min(mPos.x.mVelocity * dt, tDis.right);
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

