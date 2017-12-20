#pragma once
#include "../GameDebug.h"
#include "../Object_Unit/Object_Unit.h"

class Object_Unit_Apple final : public Object_Unit {
private:
    bool mFlip;
public:
    Object_Unit_Apple(float x, float y, bool isFlip);
    ~Object_Unit_Apple(){};

    void ObjectUpdateEvent(float dt);
};
