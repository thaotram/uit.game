#pragma once
#include "../GameDebug.h"
#include "../Object_Unit/Object_Unit.h"
#include "../Object_Unit_Final/Object_Unit_Disappear.h"
#include "../Object_Unit_Final/Object_Unit_Knife.h"

class Object_Unit_Enemy_Jarfar final : public Object_Unit {
private:

public:
    Object_Unit_Enemy_Jarfar(float x, float y);
    ~Object_Unit_Enemy_Jarfar();
    void ObjectUpdateEvent(float dt);
    void ObjectEachState();
    void ObjectIntersect(Object* pObject);
};
