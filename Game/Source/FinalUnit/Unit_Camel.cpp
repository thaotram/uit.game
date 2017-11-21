#include "Unit_Camel.h"

Unit_Camel::Unit_Camel() : Unit("Camel") {
	this->Set(
		new Unit_Entity({ 100, 166 }, "pedal")
	);
}