#pragma once
#include "../Object/Object.h"
#include "../../Define.h"
#include "../Scene/Scene.h"

class Object_Status : public Object {
protected:
public:
	Object_Status(string pName);
	~Object_Status() {};

	bool mAutoNextFrame;

	virtual void ObjectUpdateEvent(float delay) {};
	void ObjectUpdateProperties(float delay);
};
