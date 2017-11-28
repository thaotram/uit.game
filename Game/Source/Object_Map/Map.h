#pragma once
#include "../Object/Object.h"
#include "../../Define.h"

using namespace std;
class Map : public Object {
public:
	Map(string pName);
	~Map() {};

	virtual void AfterAddToScene() {};
	virtual void BeforeRender(float delay) {}

	void ObjectRender(float delay);
};