#include "Unit_Aladdin.h"

Unit_Aladdin::Unit_Aladdin() : Unit("Aladdin") {
	this->Set(
		new Unit_Entity({ 50, 166 }, "stand_still")
	);
	animation = this->Get()->GetAnimation();
	state = animation->State();

	this->Get()->mToZeroFunction = ([=] {
		if (*state == "sit_throwapple") {
			animation->Set("stand_sit", 4);
		}
		if (*state == "stand_sit_to_still") {
			animation->Set("stand_still", 1);
		}
		if (*state == "stand_up_to_still") {
			animation->Set("stand_still", 1);
		}
	});
}

bool Unit_Aladdin::UpdateUnit()
{
	map<int, bool> * Key = GameGlobal::GetInput();

	bool K_UP = (*Key)[VK_UP];
	bool K_DOWN = (*Key)[VK_DOWN];
	bool K_LEFT = (*Key)[VK_LEFT];
	bool K_RIGHT = (*Key)[VK_RIGHT];
	bool K_Z = (*Key)['Z'];
	bool K_X = (*Key)['X'];
	bool K_C = (*Key)['C'];

	if (*state == "stand_still") {
		if (K_UP) {
			animation->Set("stand_up", 1);
		}
		if (K_DOWN) {
			animation->Set("stand_sit", 1);
		}
	}
	if (*state == "stand_up") {
		if (!K_UP) {
			animation->Set("stand_up_to_still", 1);
		}
	}
	if (*state == "stand_sit") {
		if (!K_DOWN) {
			animation->Set("stand_sit_to_still", 1);
		}
		if (K_DOWN && K_Z) {
			animation->Set("sit_throwapple", 1);
		}
	}
	if (*state == "sit_throwapple") {
		//if (!K_Z) {
		//	animation->Set("sit_throwapple", 1);
		//}
	}


	return false;
}
