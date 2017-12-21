#pragma once
#include <list>
#include "../Object/Object.h"

class Scene_Status : public list<Object *> {
private:
    void operator<<(Object *pObject);

public:
    Scene_Status();
    ~Scene_Status(){};
    void ObjectUpdateEvent(float delay);
	void ObjectRender(float delay);
};
