#pragma once
#include "../Object/Object.h"
#include "../../Define.h"
#include "../Scene/Scene.h"

class Object_Unit : public Object {
protected:
public:
	Object_Unit(string pName);
	~Object_Unit() {};

	bool mAutoNextFrame;
	void AfterAddToScene();

	virtual void ObjectUpdateEvent(float delay) {};
	void ObjectUpdateProperties(float delay);
};
