#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../Scene/Scene.h"

class Object_Unit_Aladdin : public Object_Unit {
private:
	string * state;
public:
	Object_Unit_Aladdin();
	void BeforeNextFrame();
};