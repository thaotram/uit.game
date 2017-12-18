#include "Object_Unit_NPC_Camel.h"
#define mAni mAnimation
#define mPos mPosition
#define mObjectStore mScene->oObjectStore

#define xx mPos.x()
#define yy mPos.y()

Object_Unit_NPC_Camel::Object_Unit_NPC_Camel(RECT u) : Object_Unit("Camel") {
    mPos.x << (float)(u.left);
    mPos.y << (float)(u.top);
    mAni.Set("pedal", 1);
}

void Object_Unit_NPC_Camel::StartAnimation() {
    mAni.SetCycleIndex(1);
}