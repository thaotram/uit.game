#include "Object_Unit_Aladdin.h"

#define ef else if
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

#define jump 260
#define speed 300

Object_Unit_Aladdin::Object_Unit_Aladdin() : Object_Unit("Aladdin") {
	mPos << V2{ WIDTH / 2, MAP_HEIGHT - 78 };
	mPos.GetX()->mType = Type::none;
	mPos.GetY()->mType = Type::gravity;

	mAni.SetState("stand");
	isJumpUp = false;
	isGround = true;
}

void Object_Unit_Aladdin::ObjectUpdateEvent(float dt) {
	mScene->mCamera = mPos.VECTOR2() - V2{ WIDTH / 2, HEIGHT - 56 };

	auto S = mAni.GetState();

	if (L) mTransform.SetFlip(true);
	ef(R) mTransform.SetFlip(false);

	if (S == "stand") {
		if (U)			mAni.Set("up", 1);
		ef(D)			mAni.Set("sit", 1);
		ef(R || L)		mAni.Set("run", 1);
		ef(Z) 			mAni.Set("stand_throwapple", 1, "stand", 1);
		ef(X) 			mAni.Set("stand_cut", 1, "stand", 1);
		ef(C) 			mAni.Set("stand_jump", 1, "stand", 1);
	}
	ef(S == "stand_jump") {
		//mAutoNextFrame = false;
		//if (!isJumpUp) {
		//	mPos.GetY()->mEase = Ease::in;
		//	mPos.GetY()->mVelocity = -jump;
		//	isJumpUp = true;
		//}
		//auto v = mPos.GetY()->mVelocity;

		//if (-jump <= v && v <= 0)
		//	mAni.SetCycleIndex(1);
		//if (0 <= v && v <= jump)		mAni.SetCycleIndex(8);

		//if (mPos.GetY()->operator()() > MAP_HEIGHT - 56) {
		//	mPos.GetY()->operator<<(MAP_HEIGHT - 56);
		//	mPos.GetY()->mEase = Ease::stop;
		//	mAni.Set("stand", 1);
		//	isJumpUp = false;
		//}
		if (R)			mPos.GetX()->operator+=(speed * dt);
		ef(L)			mPos.GetX()->operator-=(speed * dt);
	}
	ef(S == "stand_jump_down") {
		if (isJumpUp) {
			isJumpUp = false;
			mPos += V2(0, 50);
			mPos.GetY()->mDuration = mTimePerFrame * 4;
			// thay thế điểm tiếp đất bằng rơi tự do, tính toán thông qua đụng độ
		}
		ef(mPos.GetY()->mEase == Ease::stop) {
			mAni.Next();
		}

		if (R)			mPos.GetX()->operator+=(speed * dt);
		ef(L)			mPos.GetX()->operator-=(speed * dt);
	}

	ef(S == "up") {
		if (mAni.GetCycleIndex() == 3) {}

		if (!U)			mAni.Set("up_to_stand", 1, "stand", 1);
		ef(U && Z)		mAni.Set("stand_throwapple", 1, "up", 3);
		ef(U && X)		mAni.Set("up_cut", 1, "up", 3);
		ef(U && C)		mAni.Set("stand_jump", 1, "stand", 1);
	}
	ef(S == "up_cut") {
		if (U)			mAni.SetNext("up", 3);
		ef(!U)			mAni.SetNext("stand", 1);

		if (D)			mAni.Set("sit", 1);
		ef(R || L)		mAni.Set("run", 1);
	}
	ef(S == "sit") {
		if (!D)			mAni.Set("sit_to_stand", 1, "stand", 1);
		ef(D && Z)		mAni.Set("sit_throwapple", 1, "sit", 4);
		ef(D && X) 	mAni.Set("sit_cut", 1, "sit", 4);
		ef(D && C)		mAni.Set("stand_jump", 1, "sit", 1);
	}

	ef(S == "run") {
		if (!R && !L)	mAni.Set("stand", 1);
		ef(R)			mPos.GetX()->operator+=(speed * dt);
		ef(L)			mPos.GetX()->operator-=(speed * dt);

		if (Z) {}			//mAni.Set("sit_throwapple", 1, "sit", 4);
		ef(X)			mAni.Set("run_cut", 1, "run", 9);
		ef(C)			mAni.Set("run_jump", 1, "run", 1);
	}
	ef(S == "run_cut") {
		if (!R && !L)	mAni.Set("stand", 1);
		ef(R)			mPos.GetX()->operator+=(speed * dt);
		ef(L)			mPos.GetX()->operator-=(speed * dt);
	}
	ef(S == "run_jump") {
		if (!isJumpUp) {
			mPos.GetY()->mEase = Ease::in;
			mPos.GetY()->mVelocity = -jump;
			isJumpUp = true;
		}

		if (mPos.GetY()->operator()() > MAP_HEIGHT - 56) {
			mPos.GetY()->operator<<(MAP_HEIGHT - 56);
			mPos.GetY()->mEase = Ease::stop;
			mAni.Set("stand", 1);
			isJumpUp = false;
		}
		if (R)			mPos.GetX()->operator+=(speed * dt);
		ef(L)			mPos.GetX()->operator-=(speed * dt);
	}

	/*
	ef (S == "run_jump_up") {
		if (!isJumpUp) {
			isJumpUp = true;
			mPos -= V2(0, 50);
			mPos.GetY()->mDuration = mTimePerFrame * 5;
		}
		ef(mPos.GetY()->mEase == Ease::stop) {
			mAni.Set("run_jump_down", 1);
		}

		if (R)			mPos.GetX()->operator+=(speed * dt);
		ef(L)			mPos.GetX()->operator-=(speed * dt);
	}
	ef (S == "run_jump_down") {
		if (isJumpUp) {
			isJumpUp = false;
			mPos += V2(0, 50);
			mPos.GetY()->mDuration = mTimePerFrame * 5;
			// thay thế điểm tiếp đất bằng rơi tự do, tính toán thông qua đụng độ
		}
		ef(mPos.GetY()->mEase == Ease::stop) {
			mAni.Next();
		}

		if (R)			mPos.GetX()->operator+=(speed * dt);
		ef(L)			mPos.GetX()->operator-=(speed * dt);
	}
	*/
}