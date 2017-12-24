#pragma once
#include <list>
using namespace std;
class Object;
class Object_List : public list<Object *> {
public:
    Object_List();
    ~Object_List();
    
    void operator<<(Object *pObject);
    void ObjectUpdateEvent(float delay);
    void ObjectRender(float delay);
};