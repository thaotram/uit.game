#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../GameDebug.h"

class Object_Unit_Enemy_Thin final : public Object_Unit
{
public:
	Object_Unit_Enemy_Thin(float x1, float x2, float y);
	~Object_Unit_Enemy_Thin();
};
