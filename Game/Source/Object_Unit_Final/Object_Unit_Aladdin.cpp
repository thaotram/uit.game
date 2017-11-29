#include "Object_Unit_Aladdin.h"
string * state;
Object_Unit_Aladdin::Object_Unit_Aladdin() : Object_Unit("Aladdin") {
	mPosition = { 50,628 };
	mAnimation.SetState("stand");

	state = mAnimation.State();
}

void Object_Unit_Aladdin::ObjectUpdateEvent(float delay) {
	auto I = GameGlobal::Input;

	if (I[LEFT]) mTransform.SetFlip(true);
	else if (I[RIGHT]) mTransform.SetFlip(false);

	if (*state == "stand") {
		if (I[UP]) {
			mAnimation.Set("up", 1);
		}
		if (I[DOWN]) {
			mAnimation.Set("sit", 1);
		}
		if (I[RIGHT]) {
			mAnimation.Set("run", 1);
		}
		if (I[LEFT]) {
			mAnimation.Set("run", 1);
		}
		if (I[Z]) {
			mAnimation.Set("stand_throwapple", 1, "stand", 1);
		}
		if (I[X]) {
			mAnimation.Set("stand_cut", 1, "stand", 1);
		}
		if (I[C]) {
			mAnimation.Set("stand_jump", 1, "stand", 1);
			//? chưa quản lý / viết các thao tác bay nhảy
		}
	}
	else if (*state == "up") {
		if (mAnimation.GetCycleIndex() == 3) {
			mScene->mCameraPosition -= {0, 3};
		}
		if (!I[UP]) {
			mAnimation.Set("up_to_stand", 1, "stand", 1);
			return;
		}
		if (I[Z]) {
			mAnimation.Set("stand_throwapple", 1, "up", 3);
		}
		if (I[X]) {
			mAnimation.Set("up_cut", 1, "up", 3);
		}
		if (I[C]) {
			mAnimation.Set("stand_jump", 1, "up", 3);	//? chưa quản lý / viết các thao tác bay nhảy
		}
	}
	else if (*state == "sit") {
		if (!I[DOWN]) {
			mAnimation.Set("sit_to_stand", 1, "stand", 1);
			return;
		}
		if (I[Z]) {
			mAnimation.Set("sit_throwapple", 1, "sit", 4);
		}
		if (I[X]) {
			mAnimation.Set("sit_cut", 1, "sit", 4);
		}
		if (I[C]) {
			mAnimation.Set("stand_jump", 1, "sit", 1);

			//? chưa quản lý / viết các thao tác bay nhảy
		}
	}
	else if (*state == "run") {
		if (I[RIGHT]) mPosition += { 11, 0};
		if (I[LEFT])  mPosition += {-11, 0};
		if (!I[RIGHT] && !I[LEFT]) {
			mAnimation.Set("I[and]", 1);
		}
		if (I[Z]) {
			//! thiếu sprite này
			//mAnimation.Set("sit_throwapple", 1, "sit", 4);
		}
		if (I[X]) {
			mAnimation.Set("run_cut", 1, "run", 9);
		}
		if (I[C]) {
			mAnimation.Set("run_jump", 1, "run", 1);
			//! chưa quản lý / viết các thao tác bay nhảy
		}
	}
	else if (*state == "run_cut") {
	}
	else if (*state == "up_to_stand") {
	}
}