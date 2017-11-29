#pragma once
#include "../Object/Object.h"
#include "../../Define.h"

class Object_Unit : public Object {
public:
	Object_Unit(string pName);
	~Object_Unit() {};

	void AfterAddToScene();

	virtual void ObjectUpdateEvent(float delay) {};
	virtual void ObjectUpdateProperties(float delay);
};
