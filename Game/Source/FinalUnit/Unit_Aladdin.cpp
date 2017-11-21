#include "Unit_Aladdin.h"

Unit_Aladdin::Unit_Aladdin() : Unit("Aladdin") {
	this->Set(
		new Unit_Entity({ 50, 166 }, "stand_still")
	);
	this->Get()->mToZeroFunction = ([=] {
		this->Get()->GetAnimation()->Set("stand_still", 1);
	});
}

bool Unit_Aladdin::UpdateUnit()
{
	Unit_Animation * animation = this->Get()->GetAnimation();
	string pState = animation->GetState();

	bool UP = GameInput::GetKeyCode(VK_UP);
	bool DOWN = GameInput::GetKeyCode(VK_DOWN);

	if (pState == "stand_still") {
		if (UP) {
			animation->Set("stand_up", 1);
		}
		if (DOWN) {
			animation->Set("stand_sit", 1);
		}
	}
	if (pState == "stand_up") {
		if (!UP) {
			animation->Set("stand_up_to_still", 1);
		}
	}
	if (pState == "stand_sit") {
		if (!DOWN) {
			animation->Set("stand_sit_to_still", 1);
		}
	}
	return false;
}
