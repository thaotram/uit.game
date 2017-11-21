#include "Unit_Guards.h"

Unit_Guards::Unit_Guards() : Unit("Guards") {
	this->mEntities["1"] = new Unit_Entity({ 150, 166 }, "pirates_cut");
	this->mEntities["2"] = new Unit_Entity({ 200, 166 }, "pirates_poke");
}