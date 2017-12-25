#include "Object_Unit_Apple.h"
#include "../Scene_Final/Scene_JafarPalace.h"
#include "../Scene_Final/Scene_AgrabahMarket.h"
#include "../Object_Unit_Final/Object_Unit_Explosion_Small.h"
#define mAni mAnimation
#define mPos mPosition
#define mObjectStore Scene::mScene->oObjectStore
#define velocityX mPos.x.mVelocity
//#define tSpeedX	490

#define xx mPos.x()
#define yy mPos.y()

//# Quả táo dùng để ném đi
Object_Unit_Apple::Object_Unit_Apple(float x, float y, bool isFlip)
    : Object_Unit("Aladdin") {
    mPos << V2{x, y};
	mPos.x.mVelocity = 500;
    mAni.Set("apple", 2);
    mTimePerFrame = 0.03f;
    mAutoNextFrame = false;
    mIsMakeDamage = false;
    mFlip = isFlip;
    Scene::mScene->mApple = max(Scene::mScene->mApple - 1, 0);
    mParty = Friend;
}

void Object_Unit_Apple::ObjectUpdateEvent(float dt) {
    tUnit = tUnitDamage = RECT{(LONG)xx - 4, (LONG)yy - 7, (LONG)xx + 3, (LONG)yy};
    tDis = mObjectStore->GetDistance(tUnit, this);
	if (!tDis.bottom || !tDis.left || !tDis.right || mIsMakeDamage) {
		mAutoNextFrame = true;
	}
	if (!mAutoNextFrame) {
		mPos.x += mFlip ?
			-min(velocityX * dt, tDis.left) :
			+min(velocityX * dt, tDis.right);
		mPos.y = yy + tDis.bottom;
		mPos.Update(dt);
	}

	if (dynamic_cast<Scene_AgrabahMarket*>(Scene::mScene)) {
		Scene::mScene->oObjectStore->Collision_Player_Enemy(this);
		if (mAutoNextFrame && mAni.GetCycleIndex() == 8) {
			mIsMarkedDelete = true;
		}
	}
	else if (dynamic_cast<Scene_JafarPalace*>(Scene::mScene)) {
		Scene::mScene->oObjectStore->Collision_Apple_Jarfar(this);
		if (mAutoNextFrame) {
			mIsMarkedDelete = true;
            mObjectStore->mLost.push_back(
                new Object_Unit_Explosion_Small(
                    xx - 6, yy - 6
                )
	        );
		}
	} 
    
}