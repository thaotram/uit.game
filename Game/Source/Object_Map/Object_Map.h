#pragma once
#include "../Object/Object.h"
#include "../../Define.h"

using namespace std;

class Object_Map : public Object {
public:
	Object_Map(string pName);
	~Object_Map() {};

	void AfterAddToScene();

	virtual void ObjectUpdateEvent(float delay) {};
	void ObjectUpdateProperties(float delay);
};