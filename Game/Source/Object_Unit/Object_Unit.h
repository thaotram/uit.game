#pragma once
#include "../Object/Object.h"
#include "../../Define.h"
#include "../Scene/Scene.h"

class Object_Unit : public Object {
public:
	Object_Unit(string pName);
	~Object_Unit() {};

	bool mAutoNextFrame;

	virtual void ObjectUpdateEvent(float delay) {};
	virtual void ObjectIntersect(Object * pObject) {};
	void ObjectUpdateProperties(float delay);
};
