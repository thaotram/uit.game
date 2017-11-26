#include "Unit_Aladdin.h"

Unit_Aladdin::Unit_Aladdin() : Unit("Aladdin") {
	mPosition = { 50,166 };
	mAnimation.SetState("stand");
	state = mAnimation.State();
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

	if (*state == "stand") {
		if (K_UP) {
			mAnimation.Set("up", 1);
		}
		if (K_DOWN) {
			mAnimation.Set("sit", 1);
		}
		if (K_RIGHT) {
			mAnimation.Set("run", 1);
			mTransform.SetFlip(false);
		}
		if (K_LEFT) {
			mAnimation.Set("run", 1);
			mTransform.SetFlip(true);
		}
		if (K_Z) {
			mAnimation.Set("stand_throwapple", 1, "stand", 1);
		}
		if (K_X) {
			mAnimation.Set("stand_cut", 1, "stand", 1);
		}
		if (K_C) {
			mAnimation.Set("stand_jump", 1, "stand", 1);
			//? chưa quản lý / viết các thao tác bay nhảy
		}
	}
	if (*state == "up") {
		if (!K_UP) {
			mAnimation.Set("up_to_stand", 1, "stand", 1);
			return false;
		}
		if (K_RIGHT) {
			mTransform.SetFlip(false);
		}
		if (K_LEFT) {
			mTransform.SetFlip(true);
		}
		if (K_Z) {
			mAnimation.Set("stand_throwapple", 1, "up", 3);
		}
		if (K_X) {
			mAnimation.Set("up_cut", 1, "up", 3);
		}
		if (K_C) {
			mAnimation.Set("stand_jump", 1, "up", 3);	//? chưa quản lý / viết các thao tác bay nhảy
		}
	}
	if (*state == "sit") {
		if (!K_DOWN) {
			mAnimation.Set("sit_to_stand", 1, "stand", 1);
			return false;
		}
		if (K_RIGHT) {
			mTransform.SetFlip(false);
		}
		if (K_LEFT) {
			mTransform.SetFlip(true);
		}
		if (K_Z) {
			mAnimation.Set("sit_throwapple", 1, "sit", 4);
		}
		if (K_X) {
			mAnimation.Set("sit_cut", 1, "sit", 4);
		}
		if (K_C) {
			mAnimation.Set("stand_jump", 1, "sit", 1);	//? chưa quản lý / viết các thao tác bay nhảy
		}
	}
	if (*state == "run") {
		if (K_RIGHT) {
			mTransform.SetFlip(false);
			*(this->GetPosition()) += Unit_Vector2(11, 0);
		}
		if (K_LEFT) {
			mTransform.SetFlip(true);
			//*(this->Get()->GetPosition()) += Unit_Vector2(-11, 0);
		}
		if (!K_RIGHT && !K_LEFT) {
			mAnimation.Set("stand", 1);
		}
		//? spriters-resource thiếu sprite này
		//if (K_Z) {
		//	mAnimation.Set("sit_throwapple", 1, "sit", 4);
		//}
		//? spriters-resource thiếu sprite này
		if (K_X) {
			mAnimation.Set("run_cut", 1, "run", 9);
		}
		if (K_C) {
			mAnimation.Set("run_jump", 1, "run", 1);	//? chưa quản lý / viết các thao tác bay nhảy
		}
	}
	if (*state == "run_cut") {
		//if (K_RIGHT) {
		//	this->Get()->GetTransform()->SetFlip(false);
		//	//*(this->Get()->GetPosition()) += Unit_Vector2(11, 0);
		//}
		//if (K_LEFT) {
		//	this->Get()->GetTransform()->SetFlip(true);
		//	//*(this->Get()->GetPosition()) += Unit_Vector2(-11, 0);
		//}
	}



	return false;
}
