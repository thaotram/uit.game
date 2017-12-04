#include "Object_Unit_Aladdin.h"
#define I GameGlobal::Input
#define L I[LEFT]
#define U I[UP]
#define R I[RIGHT]
#define D I[DOWN]
#define Z I[CHAR_Z]
#define X I[CHAR_X]
#define C I[CHAR_C]

#define mAni mAnimation
#define mPos mPosition

Object_Unit_Aladdin::Object_Unit_Aladdin() : Object_Unit("Aladdin") {
	mPos << V2{ WIDTH / 2, MAP_HEIGHT - 62 };

	//mPos.GetX().

	mAni.SetState("stand");
	isJumpUp = false;
	isGround = true;
}

void Object_Unit_Aladdin::ObjectUpdateEvent(float dt) {
	mPos.Update(dt);
	mScene->mCamera = V2(50, MAP_HEIGHT - HEIGHT - 56);
		// mPos.VECTOR2() - V2{ WIDTH / 2, HEIGHT - 56 };

	auto S = mAni.GetState();

	//if (L) mTransform.SetFlip(true);
	//else if (R) mTransform.SetFlip(false);

	if (S == "stand") {
		if		(U)			mAni.Set("up", 1);
		else if (D)			mAni.Set("sit", 1);
		else if (R || L)	mAni.Set("run", 1);
		else if (Z) 		mAni.Set("stand_throwapple", 1, "stand", 1);
		else if (X) 		mAni.Set("stand_cut", 1, "stand", 1);
		else if (C) 		mAni.Set("stand_jump_up", 1);
	}
	else if (S == "stand_jump_up") {
		if (!isJumpUp) {
			isJumpUp = true;
			mAni.SetNext("stand_throw_down", 1);
			mPos -= V2(0, 50);	
			mPos.GetY()->mMaxTime = 0.12f;
		}
	}
	else if (S == "stand_throw_down") {
		if (isJumpUp) {
			isJumpUp = false;
			mAni.SetNext("stand", 1);
			mPos += V2(0, 50);	
			// thay thế điểm tiếp đất bằng rơi tự do, tính toán thông qua đụng độ
			mPos.GetY()->mMaxTime = 0.12f;
		}
	}
	else if (S == "up") {
		if (mAni.GetCycleIndex() == 3) {}

		if (!U)				mAni.Set("up_to_stand", 1, "stand", 1);
		else if (U && Z)	mAni.Set("stand_throwapple", 1, "up", 3);
		else if (U && X)	mAni.Set("up_cut", 1, "up", 3);
		else if (U && C)	mAni.Set("stand_jump_up", 1, "stand", 1);		//? Jump
	}
	else if (S == "up_cut") {
		if (U)				mAni.SetNext("up", 3);
		else if (!U)		mAni.SetNext("stand", 1);

		if (D)				mAni.Set("sit", 1);
		else if (R || L)	mAni.Set("run", 1);
	}
	else if (S == "sit") {
		//mPosition.SetAuto(0, 0);
		if (!D)				mAni.Set("sit_to_stand", 1, "stand", 1);
		else if (D && Z)	mAni.Set("sit_throwapple", 1, "sit", 4);
		else if (D && X) 	mAni.Set("sit_cut", 1, "sit", 4);
		else if (D && C)	mAni.Set("stand_jump_up", 1, "sit", 1);			//! jump
	}
	else if (S == "run") {
		if (!R && !L)		mAni.Set("stand", 1);
		else if (R) {}
		else if (L) {}

		if (Z) {}			//mAni.Set("sit_throwapple", 1, "sit", 4);
		else if (X)			mAni.Set("run_cut", 1, "run", 9);
		else if (C)			mAni.Set("run_jump", 1, "run", 1);
	}
	else if (S == "run_cut") {}
	else if (S == "up_to_stand") {}
}