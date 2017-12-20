#pragma once
#include "../GameDebug.h"
#include "../Object_Unit/Object_Unit.h"

class Object_Unit_Enemy_Fat final : public Object_Unit {
public:
    Object_Unit_Enemy_Fat(RECT u);
    ~Object_Unit_Enemy_Fat(){};
    void ObjectGetDame(Object* pObject);
    void ObjectUpdateEvent(float delay);
};
