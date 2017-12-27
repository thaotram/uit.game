#include "Object_Unit_Static_Black_Magic_Lamp.h"

#define mAni mAnimation
#define mPos mPosition
Object_Unit_Static_Black_Magic_Lamp::Object_Unit_Static_Black_Magic_Lamp(RECT u)
    : Object_Unit("Item") {
    mPos.x << (float)(u.left);
    mPos.y << (float)(u.top);
    mAni.Set("black_magiclamp", 1);
    mAutoNextFrame = false;
	mSourceRect.Update(this);
	tUnit = GetBound();
}

void Object_Unit_Static_Black_Magic_Lamp::ObjectIntersect(Object* pObject) {
    mAutoNextFrame = true;
    mIsMarkedDelete = true;
    Scene::mScene->oObjectStore->mLost.push_back(
        new Object_Unit_Explosion_Big(mPos.x() + 16, mPos.y() - 5)
    );
}

void Object_Unit_Static_Black_Magic_Lamp::ObjectUpdateEvent(float dt) {}
