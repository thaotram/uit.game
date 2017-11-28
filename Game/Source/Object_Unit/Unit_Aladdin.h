#pragma once
#include "../Object/Object.h"
#include "../Scene/Scene.h"

class Object_Aladdin : public Object {
private:
	string * state;
public:
	Object_Aladdin();
	void BeforeNextFrame();
};