#include "Object_Unit_Knife.h"
#include "../Object_Unit_Final/Object_Unit_Explosion_Tiny.h"
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

	mPos.x.mVelocity = pVelocityX;
	mPos.y.mVelocity = pVelocityY;
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
	Scene::mScene->oObjectStore->Collision_Enemy_Player(this);
	
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

}
void Object_Unit_Knife::ObjectIntersect(Object* pObject) {
	mAutoNextFrame = true;
	mIsMarkedDelete = true;
}

void Object_Unit_Knife::ObjectIntersectBack(Object * pObject) {
	mFlip ^= 1;
	mPos.x.mVelocity = 100;
	mPos.y.mVelocity = -100;
}

