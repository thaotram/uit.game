#pragma once
#include "../Unit.h"
class Unit_Status : public Unit
{
private: 
	Unit_Entity * number;

public:
	Unit_Status();
	bool UpdateUnit();
};

