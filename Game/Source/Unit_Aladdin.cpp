#include "Unit_Aladdin.h"

Unit_Aladdin::Unit_Aladdin() : Unit("Aladdin") {
	this->SetPosition(50, 50);
	this->mAnimation.SetState("levelcomplete");
}

bool Unit_Aladdin::UpdateAnimation() {
	this->mAnimation++;
	return true;
}
