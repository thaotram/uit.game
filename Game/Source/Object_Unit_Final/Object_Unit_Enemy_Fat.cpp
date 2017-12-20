#include "Object_Unit_Enemy_Fat.h"
#define mAni mAnimation
#define mPos mPosition
#define mObjectStore Scene::mScene->oObjectStore

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_Enemy_Fat::Object_Unit_Enemy_Fat(RECT u) : Object_Unit("Guards") {
    mPos.x << (float)(u.left + u.right) / 2;
    mPos.y << (float)(u.top);
    mAni.Set("fat_eat", 1);
}

void Object_Unit_Enemy_Fat::ObjectGetDame(Object* pObject) {
    mHealthPoint--;
    mAni.Set("fat_hurt", 1, "fat_eat", 1);
    if (mHealthPoint <= 0) {
        mIsMarkedDelete = true;
    }
}

void Object_Unit_Enemy_Fat::ObjectUpdateEvent(float dt) { 
	ObjectEachState(); 
}

void Object_Unit_Enemy_Fat::ObjectEachState() {}