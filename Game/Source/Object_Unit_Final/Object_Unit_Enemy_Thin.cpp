#pragma once
#include "Object_Unit_Enemy_Thin.h"
#include "Object_Unit_Aladdin.h"

#define mAni mAnimation
#define mPos mPosition
#define mObjectStore Scene::mScene->oObjectStore
#define isFlip (mTransform.GetFlip())

#define xx mPos.x()
#define yy mPos.y()
#define state mAni.GetState()

Object_Unit_Enemy_Thin::Object_Unit_Enemy_Thin(RECT u)
    : Object_Unit("Guards"), mLimit(u) {
    mPos.x << (float)(u.left + u.right) / 2;
    mPos.y << (float)(u.top);
    mAni.Set("thin_stand", 1);
    mPos.x.mVelocity = 180;
    mTimePerFrame = 0.06f;
    mHealthPoint = 2;
    mParty = Enemy;
    mAutoNextFrame = true;
}

Object_Unit_Enemy_Thin::~Object_Unit_Enemy_Thin() {}

void Object_Unit_Enemy_Thin::ObjectUpdateEvent(float dt) {
    if (mHealthPoint == 0) {
        mIsMarkedDelete = true;
    }

    tUnit = RECT{(LONG)xx - 15, (LONG)yy - 60, (LONG)xx + 15, (LONG)yy};
    tDis = mObjectStore->GetDistance(tUnit, this);
    tDt = dt;
    ObjectEachState();
    mObjectStore->Collision_Enemy_Player(this);
}
// tam danh
#define range 100
// tamnhin
#define visible 160
void Object_Unit_Enemy_Thin::ObjectEachState() {
    float playerX = Scene::mScene->oPlayer->GetPosition()->x();
    mTransform.SetFlip(playerX > xx);
    float distance = abs(xx - playerX);
    tUnitDamage = RECT{0, 0, 0, 0};

    if (state == "thin_run") {
        mPos.x += playerX > xx ? +(mPos.x.mVelocity * tDt)
                               : -(mPos.x.mVelocity * tDt);
        mPos.Update(tDt);
        if (xx < mLimit.left) {
            mPos.x << (float)mLimit.left;
        } else if (xx > mLimit.right) {
            mPos.x << (float)mLimit.right;
        }
    }

    if (state != "thin_hurt") {
        if (distance < range) {
            if (state != "thin_hit") mAni.Set("thin_hit", 1);
        } else if (distance < visible) {
            if ((xx == mLimit.right && playerX > xx) ||
                (xx == mLimit.left && playerX < xx)) {
                if (state != "thin_stand") mAni.Set("thin_stand", 1);
            } else if (state != "thin_run")
                mAni.Set("thin_run", 1);
        } else {
            if (state != "thin_stand") mAni.Set("thin_stand", 1);
        }
    }
    if (state == "thin_hit") {
        if (mAni.GetCycleIndex() == 3) {
            tUnitDamage =
                RECT{(LONG)((isFlip) ? (xx - 26) : (xx - 77)), (LONG)(yy - 46),
                     (LONG)((isFlip) ? (xx + 77) : (xx + 26)), (LONG)(yy - 18)};
        } else {
            mIsMakeDamage = false;
        }
    }
}

void Object_Unit_Enemy_Thin::ObjectIntersect(Object* pObject) {
    mHealthPoint--;
    mAni.Set("thin_hurt", 1, "thin_stand", 1);
    if (mHealthPoint <= 0) {
        mIsMarkedDelete = true;
        Scene::mScene->oObjectStore->mLost.push_back(
            new Object_Unit_Disappear(mPos.x() - 3, mPos.y() - 4));
    }
}
