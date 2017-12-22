#pragma once
#include "../Object/Object.h"
#include "../../Define.h"
#include "../Scene/Scene.h"

class Object_Screen : public Object {
public:
	bool mAutoNextFrame = false;
	Object_Screen(string pName);
	~Object_Screen() {};

	virtual void ObjectUpdateEvent(float delay) {};
	void ObjectUpdateProperties(float delay);

};
