#include "Object_Unit_Aladdin.h"
#define I GameGlobal::Input

Object_Unit_Aladdin::Object_Unit_Aladdin() : Object_Unit("Aladdin") {
	mPosition << V2{ WIDTH / 2, MAP_HEIGHT - 50 };
	mAnimation.SetState("stand");
}

void Object_Unit_Aladdin::ObjectUpdateEvent(float delay) {
	mPosition.Update(delay);
	// Calc Camera
	mScene->mCamera << mPosition.VECTOR2() - V2{ WIDTH / 2,HEIGHT - 50 };

	auto S = mAnimation.GetState();

	if (I[LEFT]) mTransform.SetFlip(true);
	else if (I[RIGHT]) mTransform.SetFlip(false);

	if (S == "stand") {
		if (I[UP])		mAnimation.Set("up", 1);
		else if (I[DOWN])	mAnimation.Set("sit", 1);
		else if (I[RIGHT])	mAnimation.Set("run", 1);
		else if (I[LEFT])	mAnimation.Set("run", 1);
		else if (I[Z]) 		mAnimation.Set("stand_throwapple", 1, "stand", 1);
		else if (I[X]) 		mAnimation.Set("stand_cut", 1, "stand", 1);
		else if (I[C]) 		mAnimation.Set("stand_jump", 1, "stand", 1);
		//! chưa quản lý / viết các thao tác bay nhảy
	}
	else if (S == "up") {
		if (mAnimation.GetCycleIndex() == 3) {
			// mScene->mCameraPosition -= {0, 2};
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
			mAnimation.Set("stand_jump", 1, "up", 3);
			//! chưa quản lý / viết các thao tác bay nhảy
		}
	}
	else if (S == "sit") {
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
			//! chưa quản lý / viết các thao tác bay nhảy
		}
	}
	else if (S == "run") {
		if (!I[RIGHT] && !I[LEFT]) {
			mAnimation.Set("stand", 1);
			mPosition.SetAuto(0, 0);
		}
		else if (I[RIGHT])	mPosition.SetAuto(280, 0);
		else if (I[LEFT])	mPosition.SetAuto(-280, 0);
		else if (I[Z]) {}	//mAnimation.Set("sit_throwapple", 1, "sit", 4);
		else if (I[X])		mAnimation.Set("run_cut", 1, "run", 9);
		else if (I[C])		mAnimation.Set("run_jump", 1, "run", 1);
		//! chưa quản lý / viết các thao tác bay nhảy
	}
	else if (S == "run_cut") {}
	else if (S == "up_to_stand") {}
}