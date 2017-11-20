#include "Unit_Aladdin.h"

Unit_Aladdin::Unit_Aladdin() : Unit("Aladdin") {
	this->mEntity["self"] = new Unit_Entity({ 50, 166 }, "stand_still");
}