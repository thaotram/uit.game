#pragma once
#include "../../Define.h"
#include "../Object/Object.h"

class Object_Screen final : public Object {
public:
	Object_Screen();
	~Object_Screen() {};
	virtual void ObjectUpdateEvent(float delay) {};
	void ObjectUpdateProperties(float delay);
};
