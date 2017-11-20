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
	string pState = this->Get()->GetAnimation()->GetState();

	if (GameInput::GetKeyCode(VK_UP)) {
		this->Get()->GetAnimation()->Set("stand_up", 1);
	}
	else {
		if (pState == "stand_up") {
			this->Get()->GetAnimation()->Set("stand_up_to_still", 1);
		};
	}

	//if (GameInput::GetKeyCode(VK_DOWN)) {
	//	this->Get()->GetAnimation()->Set("stand_sit", 1);
	//}
	//else {
	//	if (this->Get()->GetAnimation()->GetState() == "stand_sit") {
	//		this->Get()->GetAnimation()->Set("stand_up_to_still", 1);
	//	};
	//}

	return false;
}
