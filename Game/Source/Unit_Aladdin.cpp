#include "Unit_Aladdin.h"
float x = 0;

Unit_Aladdin::Unit_Aladdin() : Unit("Aladdin") {
	this->SetPosition(50, 166);
	this->mAnimation.SetState("stand_still");
}

bool Unit_Aladdin::UpdateAnimation() {
	this->mAnimation++;
	return true;
}
