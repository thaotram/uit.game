#include "Object_Unit_Aladdin.h"
#define I GameGlobal::Input
#define mAni mAnimation

Object_Unit_Aladdin::Object_Unit_Aladdin() : Object_Unit("Aladdin") {
	mPosition = V2{ WIDTH / 2, MAP_HEIGHT - 50 };
	mAni.SetState("stand");
}

void Object_Unit_Aladdin::ObjectUpdateEvent(float delay) {
	mScene->mCamera = mPosition.VECTOR2() - V2{ WIDTH / 2,HEIGHT - 50 };

	auto S = mAni.GetState();

	if (I[LEFT]) mTransform.SetFlip(true);
	else if (I[RIGHT]) mTransform.SetFlip(false);

	if (S == "stand") {
		if (I[UP])						mAni.Set("up", 1);
		else if (I[DOWN])				mAni.Set("sit", 1);
		else if (I[RIGHT] || I[LEFT])	mAni.Set("run", 1);
		else if (I[Z]) 					mAni.Set("stand_throwapple", 1, "stand", 1);
		else if (I[X]) 					mAni.Set("stand_cut", 1, "stand", 1);
		else if (I[C]) 					mAni.Set("stand_jump", 1, "stand", 1);
		//! chưa quản lý / viết các thao tác bay nhảy
	}
	else if (S == "up") {
		if (mAni.GetCycleIndex() == 3) {}

		if (!I[UP])					mAni.Set("up_to_stand", 1, "stand", 1);
		else if (I[UP] && I[Z])		mAni.Set("stand_throwapple", 1, "up", 3);
		else if (I[UP] && I[X])		mAni.Set("up_cut", 1, "up", 3);
		else if (I[UP] && I[C])		mAni.Set("stand_jump", 1, "stand", 1);		//? Jump
	}
	else if (S == "up_cut") {
		if (I[UP])			mAni.SetNext("up", 3);
		else if (!I[UP])	mAni.SetNext("stand", 1);

		if (I[DOWN])					mAni.Set("sit", 1);
		else if (I[RIGHT] || I[LEFT])	mAni.Set("run", 1);
	}
	else if (S == "sit") {
		//mPosition.SetAuto(0, 0);
		if (!I[DOWN])				mAni.Set("sit_to_stand", 1, "stand", 1);
		else if (I[DOWN] && I[Z])	mAni.Set("sit_throwapple", 1, "sit", 4);
		else if (I[DOWN] && I[X]) 	mAni.Set("sit_cut", 1, "sit", 4);
		else if (I[DOWN] && I[C])	mAni.Set("stand_jump", 1, "sit", 1);			//! jump
	}
	else if (S == "stand_jump") {
		if (mAni.GetCycleIndex() == 1) {
			//mPosition = mPosition.VECTOR2() - V2{ 0,30 };
		};
	}
	else if (S == "run") {
		if (!I[RIGHT] && !I[LEFT]) mAni.Set("stand", 1);
		else if (I[RIGHT])	{} 
		else if (I[LEFT])	{} 

		if (I[Z]) {}		//mAni.Set("sit_throwapple", 1, "sit", 4);
		else if (I[X])		mAni.Set("run_cut", 1, "run", 9);
		else if (I[C])		mAni.Set("run_jump", 1, "run", 1);
	}
	else if (S == "run_cut") {}
	else if (S == "up_to_stand") {}
}