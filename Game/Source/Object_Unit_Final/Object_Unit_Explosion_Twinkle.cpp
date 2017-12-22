#include "Object_Unit_Explosion_Twinkle.h"
#define mAni mAnimation
#define mPos mPosition
#define L I[LEFT]
#define R I[RIGHT]
#define mObjectStore Scene::mScene->oObjectStore
#define tSpeedX 400

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_Explosion_Twinkle::Object_Unit_Explosion_Twinkle(float x, float y,
                                                             bool isFlip)
    : Object_Unit("Twinkle") {
    mPos.x << x;
    mPos.y << y;
    mAni.Set("twinkle", 1);
    mAutoNextFrame = true;
    mTimePerFrame = 0.02f;
    // mTransform.SetFlip(isFlip);
}

Object_Unit_Explosion_Twinkle::~Object_Unit_Explosion_Twinkle() {}

void Object_Unit_Explosion_Twinkle::ObjectUpdateEvent(float dt) {
    if (mAni.GetCycleIndex() == 12) {
        mIsMarkedDelete = true;
    }
}
