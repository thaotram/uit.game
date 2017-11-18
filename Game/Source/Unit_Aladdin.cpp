#include "Unit_Aladdin.h"

Unit_Aladdin::Unit_Aladdin() : Unit("Aladdin") {
	this->SetPosition(200, 480);
	this->GetAnimation()->SetState("run");
	x = 5;
}

void Unit_Aladdin::BeforeUpdateUnit() {
	x++;
	this->SetPosition(x, 480);
}
