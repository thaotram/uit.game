#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../GameDebug.h"

class Object_Unit_Enemy_Circus final : public Object_Unit
{
public:
	Object_Unit_Enemy_Circus(RECT u);
	~Object_Unit_Enemy_Circus();
	void ObjectGetDame(Object * pObject);
};

