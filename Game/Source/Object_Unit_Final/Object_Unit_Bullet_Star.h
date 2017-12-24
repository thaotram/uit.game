#pragma once
#include "../Object_Unit/Object_Unit.h"

class Object_Unit_Bullet_Star final : public Object_Unit {
public:
    Object_Unit_Bullet_Star(float x, float y);
    ~Object_Unit_Bullet_Star(){};
    void ObjectUpdateEvent(float dt);
};
