#pragma once
#include <list>
using namespace std;
class Object;
class Scene_Background : public list<Object *> {
public:
    Scene_Background();
    ~Scene_Background();
    
    void operator<<(Object *pObject);
    void ObjectUpdateEvent(float delay);
    void ObjectRender(float delay);
};