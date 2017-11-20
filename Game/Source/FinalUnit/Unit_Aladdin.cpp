#include "Unit_Aladdin.h"

Unit_Aladdin::Unit_Aladdin() : Unit("Aladdin") {
	SetPosition(50, 166);
	mAnimation.SetState("stand_still");
}

bool Unit_Aladdin::UpdateSprite()
{
	mAnimation++;
	mSourceRect << this;
	mTransform << this;
	return true;
}