#include "Unit_Aladdin.h"

Unit_Aladdin::Unit_Aladdin() : Unit("Aladdin") {
	this->SetPosition(50, 50);
	this->GetAnimation()->SetState("run");
}

void Unit_Aladdin::BeforeUpdateUnit() {
	//this->SetPosition(x, 480);
}
