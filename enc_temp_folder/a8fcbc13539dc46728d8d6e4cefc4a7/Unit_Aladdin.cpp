#include "Unit_Aladdin.h"

Unit_Aladdin::Unit_Aladdin() : Unit("Aladdin") {
	this->Set(
		new Unit_Entity({ 50, 166 }, "stand_still")
	);
	this->Get()->mEndFunction = ([=] {
		this->Get()->GetAnimation()->Set("stand_still", 1);
	});
}

bool Unit_Aladdin::UpdateUnit()
{
	if (GameInput::GetKeyCode(VK_UP)) {
		this->Get()->GetAnimation()->Set("stand_up", 1);
	}
	else {
		if (this->Get()->GetAnimation()->GetState() == "stand_up") {
			this->Get()->GetAnimation()->Set("stand_up_to_still", 1);
		};
	}

	if (GameInput::GetKeyCode(VK_DOWN)) {
		this->Get()->GetAnimation()->Set("stand_sit", 1);
	} else {
		if (this->Get()->GetAnimation()->GetState() == "stand_sit") {
			this->Get()->GetAnimation()->Set("stand_up_to_still", 1);
		};
	}
	//mEntities.Update(this);
	return false;
}
