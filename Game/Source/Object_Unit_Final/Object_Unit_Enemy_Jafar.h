#pragma once
#include "../GameDebug.h"
#include "../Object_Unit/Object_Unit.h"
// #include "../Object_Unit_Final/Object_Unit_Disappear.h"
#include "../Object_Unit_Final/Object_Unit_Bullet_Star.h"

class Object_Unit_Enemy_Jafar final : public Object_Unit {
private:
    bool mIsCash;
public:
    Object_Unit_Enemy_Jafar(float x, float y);
    ~Object_Unit_Enemy_Jafar();
    void ObjectUpdateEvent(float dt);
    void ObjectEachState();
    void ObjectIntersect(Object* pObject);
};
