#pragma once
#include "Object_Unit_Enemy_Fat.h"
#include "Object_Unit_Aladdin.h"

#define mAni mAnimation
#define mPos mPosition
#define mObjectStore Scene::mScene->oObjectStore
#define isFlip (mTransform.GetFlip())

#define xx mPos.x()
#define yy mPos.y()
#define state mAni.GetState()

Object_Unit_Enemy_Fat::Object_Unit_Enemy_Fat(RECT u)
    : Object_Unit("Guards"), mLimit(u) {
    mPos.x << (float)(u.left + u.right) / 2;
    mPos.y << (float)(u.top);
    mAni.Set("fat_eat", 1);
    mPos.x.mVelocity = 130;
    mTimePerFrame = 0.09f;
    mParty = Enemy;
    mAutoNextFrame = true;
	mSound = new GameSound(L"Sound/SFX/Wall Hit 2.wav");
}

void Object_Unit_Enemy_Fat::ObjectUpdateEvent(float dt) {
    tUnit = RECT{(LONG)xx - 15, (LONG)yy - 46, (LONG)xx + 15, (LONG)yy};
    tDis = mObjectStore->GetDistance(tUnit, this);
    tDt = dt;
    ObjectEachState();
}
// tam danh
#define range 110
// tamnhin
#define visible 160
#define visibleY 40
void Object_Unit_Enemy_Fat::ObjectEachState() {
    float playerX = Scene::mScene->oPlayer->GetPosition()->x();
	float playerY = Scene::mScene->oPlayer->GetPosition()->y();
	float distanceY = abs(yy - playerY);
    mTransform.SetFlip(playerX > xx);
    float distance = abs(xx - playerX);

    if (state == "fat_run") {
        mPos.x += playerX > xx ? +(mPos.x.mVelocity * tDt)
                               : -(mPos.x.mVelocity * tDt);
        mPos.Update(tDt);
        if (xx < mLimit.left) {
            mPos.x << (float)mLimit.left;
        } else if (xx > mLimit.right) {
            mPos.x << (float)mLimit.right;
        }
    }

    if (state != "fat_hurt") {
        if (distance < range) {
            if (state != "fat_throwknife") mAni.Set("fat_throwknife", 1);
        } else if (distance < visible && distanceY < visibleY) {
            if ((xx == mLimit.right && playerX > xx) ||
                (xx == mLimit.left && playerX < xx)) {
                if (state != "fat_eat") mAni.Set("fat_eat", 1);
            } else if (state != "fat_run")
                mAni.Set("fat_run", 1);
        } else {
            if (state != "fat_eat") mAni.Set("fat_eat", 1);
        }
    }
    if (state == "fat_throwknife") {
        if (mAni.GetCycleIndex() == 1) {
            mIsThrow = false;
        } else if (mAni.GetCycleIndex() == 4 && !mIsThrow) {
            Scene::mScene->oObjectStore->mLost.push_back(new Object_Unit_Knife(
                xx + 42 * (isFlip ? +1 : -1), yy - 30, 400, 0, isFlip));
            mIsThrow = true;
        }
    }
}

void Object_Unit_Enemy_Fat::ObjectIntersect(Object* pObject) {
    mHealthPoint--;
    mAni.Set("fat_hurt", 1, "fat_eat", 1);
    if (mHealthPoint <= 0) {
        mIsMarkedDelete = true;
		if (!isPlay) {
			mSound->Play();
			isPlay = true;
		}
        Scene::mScene->oObjectStore->mLost.push_back(
            new Object_Unit_Disappear(mPos.x() - 3, mPos.y() - 4));
    }
}