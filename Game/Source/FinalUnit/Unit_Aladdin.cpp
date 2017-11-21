#include "Unit_Aladdin.h"

Unit_Aladdin::Unit_Aladdin() : Unit("Aladdin") {
	this->Set(
		new Unit_Entity({ 50, 166 }, "stand_still")
	);
	animation = this->Get()->GetAnimation();
	state = animation->State();

	//this->Get()->mToZeroFunction = ([=] {
	//	if (*state == "stand_throwapple") {
	//		animation->Set("stand_still", 1);
	//	}
	//	if (*state == "sit_throwapple") {
	//		animation->Set("sit", 4);
	//	}
	//	if (*state == "sit_to_stand") {
	//		animation->Set("stand_still", 1);
	//	}
	//	if (*state == "up_to_stand") {
	//		animation->Set("stand_still", 1);
	//	}
	//});
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
			animation->Set("up", 1);
		}
		if (K_DOWN) {
			animation->Set("sit", 1);
		}
		if (K_RIGHT) {
			animation->Set("run", 1);
			this->Get()->GetTransform()->SetFlip(false);
		}
		if (K_LEFT) {
			animation->Set("run", 1);
			this->Get()->GetTransform()->SetFlip(true);
		}
		if (K_Z) {
			animation->Set("stand_throwapple", 1, "stand_still", 1);
		}
		if (K_X) {
			animation->Set("stand_cut", 1, "stand_still", 1);
		}
		if (K_C) {
			animation->Set("stand_jump", 1, "stand_still", 1); //? Lỗi
		}
	}
	if (*state == "up") {
		if (!K_UP) {
			animation->Set("up_to_stand", 1, "stand_still", 1);
			return false;
		}
		if (K_Z) {
			animation->Set("stand_throwapple", 1, "up", 3);
		}
		if (K_X) {
			animation->Set("up_cut", 1, "up", 3);
		}
		if (K_C) {
			animation->Set("stand_jump", 1, "up", 3);	//? Lỗi
		}
	}
	if (*state == "sit") {
		if (!K_DOWN) {
			animation->Set("sit_to_stand", 1, "stand_still", 1);
			return false;
		}
		if (K_Z) {
			animation->Set("sit_throwapple", 1, "sit", 4);
		}
		if (K_X) {
			animation->Set("sit_cut", 1, "sit", 4);
		}
		if (K_C) {
			animation->Set("stand_jump", 1, "sit", 1);	//? Lỗi
		}
	}
	if (*state == "run") {
		if (K_RIGHT) {
			this->Get()->GetTransform()->SetFlip(false);
		}
		if (K_LEFT) {
			this->Get()->GetTransform()->SetFlip(true);
		}
		if (!K_RIGHT && !K_LEFT) {
			animation->Set("stand_still", 1);

		}
		//if (K_Z) {
		//	animation->Set("sit_throwapple", 1, "sit", 4);
		//}
		//if (K_X) {
		//	animation->Set("sit_cut", 1, "sit", 4);
		//}
		//if (K_C) {
		//	animation->Set("stand_jump", 1, "sit", 1);	//? Lỗi
		//}
	}


	return false;
}
