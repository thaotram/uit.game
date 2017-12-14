#pragma once
#include "../Object/Object.h"
#include "../../Define.h"
#include "../Scene/Scene.h"

class Object_Status : public Object {
public:
	Object_Status(string pName);
	~Object_Status() {};

	virtual void ObjectUpdateEvent(float delay) {};
	void ObjectUpdateProperties(float delay);

};
