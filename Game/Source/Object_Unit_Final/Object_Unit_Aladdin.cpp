#include "Object_Unit_Aladdin.h"
#include "../Object_Unit_Final/Object_Unit_Apple.h"
#include "../GameDebug.h"
#include "../../Define.h"

#define isRender	obj->mIsRender

#define I GameGlobal::Input
#define L I[LEFT]
#define U I[UP]
#define R I[RIGHT]
#define D I[DOWN]
#define Z I[CHAR_Z]
#define X I[CHAR_X]
#define C I[CHAR_C]

#define mAni	mAnimation
#define mPos	mPosition
#define	mCam	mScene->mCamera
#define	mBlock	mScene->mMapBlock

#define xx mPos.x()
#define yy mPos.y()

#define state	mAni.GetState()

bool isIntersect(RECT a, RECT b) {
	return
		a.left < b.right &&
		a.right > b.left &&
		a.top <= b.bottom &&
		a.bottom >= b.top;
}

Object_Unit_Aladdin::Object_Unit_Aladdin() : Object_Unit("Aladdin") {
	mPos << V2{ 2626 , 140 };
	mAni.Set("stand", 1);
	mIsOnDropBlock = false;
}

void Object_Unit_Aladdin::ObjectUpdateEvent(float dt) {
	//# Tính toán lại giá trị các biến tạm
	tDt = dt;
	tJump = 380;
	tSpeedX = 200;
	tSpeedY = 100;
	tIsChangeX = tIsChangeY = true;
	tUnit = RECT{
		(LONG)xx - unitWidth / 2,
		(LONG)yy - unitHeight,
		(LONG)xx + unitWidth / 2,
		(LONG)yy
	};
	tDis = mBlock->GetDistance(tUnit, this);
	tRope = mBlock->GetRope(tUnit, tSpeedX * tDt);
	tBar = mBlock->GetBar(tUnit, mPos.y.mVelocity * tDt);

	//# Các thao tác tính toán / cập nhật
	ObjectEachState();
	ObjectAfterEachState();
	ObjectCheckCollision();
}
void Object_Unit_Aladdin::ObjectEachState() {
	//# Each State
	if (state == "") {
		mAni.Set("stand", 1);
	}
	else if (state == "stand") {
		mAutoNextFrame = true;
		mTimePerFrame = 0.06f;
		tIsChangeX = false;
		if (U)						mAni.Set("up", 1);
		else if (D)					mAni.Set("sit", 1);
		else if (R || L)			mAni.Set("run", 1);
		else if (Z) {
			Z = false;
			mAni.Set("stand_throwapple", 1, "stand", 1);
			mScene->Add(mScene->itPlayer, new Object_Unit_Apple(xx, yy - 55), itThrowApple);
		}
		else if (X) {
			X = false;
			mAni.Set("stand_cut", 1, "stand", 1);
		}
		else if (C && tDis.bottom <= 10) {
			C = false;
			mAutoNextFrame = false;
			mAni.Set("stand_jump", 1, "stand", 1) && mPos.y.SetVelocity(-tJump);
		}
	}
	else if (state == "stand_cut") {
		X = false;
		mTimePerFrame = 0.03f;
		tIsChangeX = false;
	}
	else if (state == "stand_throwapple") {
		mTimePerFrame = 0.03f;
		tIsChangeX = false;
		L = R = false;
		if (mAni.GetCycleIndex() == 3) {
			((Object_Unit_Apple *)(*itThrowApple))->ThrowApple(
				mTransform.GetFlip()
			);
		}
	}
	else if (state == "stand_jump") {
		C = false;
		mTimePerFrame = 0.06f;
		if (tDis.bottom == 0 && mPos.y.mVelocity == 0) {
			mAni.Set("stand", 1);
		}
		else if (
			tDis.bottom < 20
			&& mPos.y.mVelocity >= 0
			&& !mAutoNextFrame
			) {
			mAutoNextFrame = true;
			mAni.SetCycleIndex(11);
		}
		else if (mAutoNextFrame && mPos.y.mVelocity == 0) {
			mAni.NextState();
		}
		else if (mAutoNextFrame)					0;
		else if (mPos.y.mVelocity <= 0.7 * -tJump)	mAni.SetCycleIndex(2);
		else if (mPos.y.mVelocity <= 0.3 * -tJump)	mAni.SetCycleIndex(3);
		else if (mPos.y.mVelocity <= 0)				mAni.SetCycleIndex(4);
		else if (mPos.y.mVelocity <= 0.3 * +tJump)	mAni.SetCycleIndex(5);
		else if (mPos.y.mVelocity <= 0.5 * +tJump)	mAni.SetCycleIndex(6);
		else if (mPos.y.mVelocity <= 0.7 * +tJump)	mAni.SetCycleIndex(7);
		else if (mPos.y.mVelocity <= 0.9 * +tJump)	mAni.SetCycleIndex(8);
		else if (mPos.y.mVelocity <= 1.0 * +tJump)	mAni.SetCycleIndex(9);
		else if (mPos.y.mVelocity <= 1.1 * +tJump)	mAni.SetCycleIndex(9);
		else if (mPos.y.mVelocity <= 1.2 * +tJump)	mAni.SetCycleIndex(10);

		if (Z) {
			Z = false;
			//mScene->Add("2", n?ew Object_Unit_Apple(xx - 12, yy - 55, mTransform.GetFlip()));
			mAni.Set("jump_throwapple", 1, "stand_jump", 4);
		}
		if (X && tDis.bottom > 50) {
			X = false;
			mAni.Set("jump_cut", 1, "stand_jump", 4);
		}
	}
	else if (state == "jump_throwapple") {
		mTimePerFrame = 0.03f;
		mAutoNextFrame = true;
		//tIsChangeX = false;
		if (mAni.GetCycleIndex() == 4) {
			//((Object_Unit*)((*mScene)["2"]))->mAutoNextFrame = true;
		}
	}
	else if (state == "jump_cut") {
		X = false;
		mTimePerFrame = 0.03f;
		mAutoNextFrame = true;
	}
	else if (state == "up") {
		mTimePerFrame = 0.06f;
		tIsChangeX = false;
		if (!U)				mAni.Set("up_to_stand", 1, "stand", 1);
		else if (U && Z)	mAni.Set("stand_throwapple", 1, "up", 3);
		else if (U && X)	mAni.Set("up_cut", 1, "up", 3);
		else if (U && C) 	mAni.Set("stand_jump", 1, "stand", 1) && mPos.y.SetVelocity(-tJump);
	}
	else if (state == "up_cut") {
		mTimePerFrame = 0.06f;
		tIsChangeX = false;
		if (R || L)			mAni.Set("run", 1);
		else if (U)			mAni.SetNext("up", 3);
		else if (D)			mAni.Set("sit", 1);
		else				mAni.SetNext("stand", 1);
	}
	else if (state == "sit") {
		mTimePerFrame = 0.06f;
		tIsChangeX = false;
		if (!D)			mAni.Set("sit_to_stand", 1, "stand", 1);
		else if (Z) {
			//mScene->Add("2", new Object_Unit_Apple(xx + 5, yy - 27, mTransform.GetFlip()));
			mAni.Set("sit_throwapple", 1, "sit", 4);
		}
		else if (X)			mAni.Set("sit_cut", 1, "sit", 4);
		else if (C) {
			C = false;
			mAni.Set("stand_jump", 1, "sit", 1) && mPos.y.SetVelocity(-tJump);
		}
	}
	else if (state == "sit_to_stand") {
		mTimePerFrame = 0.06f;
		tIsChangeX = false;
		mAutoNextFrame = true;
	}
	else if (state == "sit_cut") {
		X = false;
		mTimePerFrame = 0.06f;
		tIsChangeX = false;
	}
	else if (state == "sit_throwapple") {
		Z = false;
		mTimePerFrame = 0.06f;
		tIsChangeX = false;
		if (mAni.GetCycleIndex() == 3) {
			//((Object_Unit*)((*mScene)["2"]))->mAutoNextFrame = true;
		}
	}
	else if (state == "run") {
		mTimePerFrame = 0.06f;
		if (!L && !R)	mAni.Set("stand", 1);
		if (Z)			0; /// "run_throwapple" - thiếu
		else if (X)			mAni.Set("run_cut", 1, "run", 9);
		else if (C && tDis.bottom <= 10) {
			// Phải ở dưới đấy thì mới được nhảy
			C = false;
			mAni.Set("run_jump", 1) && mPos.y.SetVelocity(-tJump);
		}
	}
	else if (state == "run_throwapple") {
		// ko có sprite
	}
	else if (state == "run_cut") {
		X = false;
		mTimePerFrame = 0.03f;
		if (!R && !L)	mAni.Set("stand", 1);
	}
	else if (state == "run_jump") {
		C = false;
		mTimePerFrame = 0.06f;
		if (mAni.GetCycleIndex() == 1 && mPos.y.mVelocity == -tJump) {
			mAutoNextFrame = false;
			// mPos.y.mVelocity = -jump;
			mAni.SetCycleIndex(1);
		}
		else if (mPos.y.mVelocity == 0 && tDis.bottom == 0) {
			mAni.Set("stand", 1);
		}
		else if (
			tDis.bottom < 20
			&& mPos.y.mVelocity > 0
			&& !mAutoNextFrame
			) {
			mAutoNextFrame = true;
			if (R || L)	mAni.SetCycleIndex(11) && mAni.SetNext("run", 11);
			else		mAni.SetCycleIndex(7) && mAni.SetNext("stand", 1);
		}
		else if (mAutoNextFrame && mPos.y.mVelocity == 0) {
			mAni.NextState();
		}
		else if (mAutoNextFrame)							0;	/// Ngưng lại ///
		else if (mPos.y.mVelocity <= 0.90 * -tJump)		mAni.SetCycleIndex(2);
		else if (mPos.y.mVelocity <= 0.60 * -tJump)		mAni.SetCycleIndex(3);
		else if (mPos.y.mVelocity <= 0.30 * -tJump)		mAni.SetCycleIndex(4);
		else if (mPos.y.mVelocity <= 0)					mAni.SetCycleIndex(5);
		else if (mPos.y.mVelocity <= 0.50 * +tJump)		mAni.SetCycleIndex(5);
		else if (mPos.y.mVelocity <= 0.90 * +tJump)		mAni.SetCycleIndex(6);
		//if (Z) mAni.Set("jump_thowapple", 1, "run_jump", 1);
		if (X) mAni.Set("jump_cut", 1, "run_jump", 1);
	}
	else if (state == "climb_still") {
		mTimePerFrame = 0.15f;
		mAutoNextFrame = true;
		tIsChangeX = tIsChangeY = false;
		if (L || R)			mAni.Set("climb_horizontal", 1);
		else if (Z) {
			Z = false;
			mAni.Set("climb_throwapple", 1, "climb_still", 1);
		}
		else if (X) {
			X = false;
			mAni.Set("climb_cut", 1, "climb_still", 1);
		}
		else if (C || tBar.first == false) {
			C = false;
			tBar.first = false;
			mAutoNextFrame = false;
			mPos.y << mPos.y() + 1;
			mAni.Set("stand_jump", 1);
		}
	}
	else if (state == "climb_vertical") { // Leo dọc
		mTimePerFrame = 0.06f;
		mPos.y.mVelocity = 0;
		mAutoNextFrame = false;
		tIsChangeX = tIsChangeY = false;
		mCurrentTime += tDt;
		auto cycleIndex = mAni.GetCycleIndex();

		if (mCurrentTime >= mTimePerFrame) {
			mCurrentTime -= mTimePerFrame;
			float	deltaY = 0;
			if (U)	deltaY = -min(tSpeedY * mTimePerFrame, abs(tUnit.top - tRope.second.top));
			else if (D)	deltaY = +min(tSpeedY * mTimePerFrame, abs(tUnit.bottom - tRope.second.bottom));

			mAni.SetCycleIndex(
				(deltaY == +tSpeedY * mTimePerFrame) ? (cycleIndex > 3 ? cycleIndex - 1 : 10) :
				(deltaY == -tSpeedY * mTimePerFrame) ? (cycleIndex < 10 ? cycleIndex + 1 : 3) :
				cycleIndex
			);
			mPos.y << yy + deltaY;
		}

		if (Z) {
			Z = false;
			mAni.Set("climb_throwapple", 1, "climb_vertical", cycleIndex);
		}
		else if (X) {
			X = false;
			mAni.Set("climb_cut", 1, "climb_vertical", cycleIndex);
		}
		else if (C) {
			C = false;
			mAni.Set("climb_jump", 1) && mPos.y.SetVelocity(-tJump);
		}
	}
	else if (state == "climb_horizontal") {
		mTimePerFrame = 0.06f;
		tSpeedX = 100;
		mAutoNextFrame = true;
		tIsChangeY = false;

		if (!L && !R)			mAni.Set("climb_still", 1);
		else if (Z) {
			Z = false;
			mAni.Set("climb_throwapple", 1, "climb_still", 1);
		}
		else if (X) {
			X = false;
			mAni.Set("climb_cut", 1, "climb_still", 1);
		}
		else if (C) {
			C = false;
			tBar.first = false;
			mAutoNextFrame = false;
			mPos.y << yy + 1;
			mAni.Set("stand_jump", 1);
		}
	}
	else if (state == "climb_throwapple") {
		mTimePerFrame = 0.06f;
		mAutoNextFrame = true;
		tIsChangeX = tIsChangeY = false;
	}
	else if (state == "climb_jump") {
		mTimePerFrame = 0.06f;
		mAutoNextFrame = false;
		if (tDis.bottom == 0)							mAni.Set("stand", 1);
		else if (mPos.y.mVelocity <= 0.9 * -tJump)		mAni.SetCycleIndex(1);
		else if (mPos.y.mVelocity <= 0.2 * -tJump)		mAni.SetCycleIndex(2);
		else if (mPos.y.mVelocity <= 0.5 * +tJump)		mAni.SetCycleIndex(3);
		else if (mPos.y.mVelocity <= 0.4 * +tJump)		mAni.SetCycleIndex(4);
		else if (mPos.y.mVelocity <= 0.5 * +tJump)		mAni.SetCycleIndex(5);
		else if (mPos.y.mVelocity <= 0.6 * +tJump)		mAni.SetCycleIndex(6);
		else if (mPos.y.mVelocity <= 0.7 * +tJump)		mAni.SetCycleIndex(7);
		else if (mPos.y.mVelocity <= 0.8 * +tJump)		mAni.SetCycleIndex(8);
		else if (mPos.y.mVelocity <= 0.9 * +tJump)		mAni.SetCycleIndex(9);
		else if (mPos.y.mVelocity <= 1.0 * +tJump)		mAni.Set("stand_jump", 4, "stand", 1);
	}
	else if (state == "climb_cut") {
		mTimePerFrame = 0.06f;
		mAutoNextFrame = true;
		tIsChangeX = tIsChangeY = false;
	}
	//# Bar & Rope
	if (mPos.y.mVelocity >= -0.2 * tJump && tRope.first) {
		if (state != "climb_vertical" &&
			state != "climb_cut" &&
			state != "climb_throwapple") {
			tIsChangeX = false;
			mCurrentTime = 0;
			mPos.x << (tRope.second.left + tRope.second.right) / 2.f;
			mAni.Set("climb_vertical", 1);
		}
	}
	else if (tBar.first) {
		if ((state != "climb_still" &&
			state != "climb_horizontal" &&
			state != "climb_cut" &&
			state != "climb_throwapple")) {
			// Đang nhảy lên
			mBlock->GetBar(tUnit, mPos.y.mVelocity *tDt);
			mPos.y << (float)tBar.second.top + unitHeight;
			mAni.Set("climb_still", 1);
			tIsChangeY = false;
		}
	}
}
void Object_Unit_Aladdin::ObjectAfterEachState() {
	//# Position
	mPos.x += !tIsChangeX ? 0 :
		R ? +min(tSpeedX * tDt, tDis.right) :
		L ? -min(tSpeedX * tDt, tDis.left) : 0;
	mPos.x.Update(tDt);
	tDis = mBlock->GetDistance(tUnit, this);

	if (!mIsOnDropBlock) {
		mPos.y = !tIsChangeY ? yy :
			yy + tDis.bottom;
	}
	mPos.y.Update(tDt);

	//# Camera
	mCam.x = min(max(0, xx - (WIDTH / 2)), MAP_WIDTH - WIDTH);
	mCam.y = min(max(0, yy - (HEIGHT - 56)), MAP_HEIGHT - HEIGHT);

	//# Flip
	mTransform.SetFlip(R ? Right : L ? Left : Stand);

	//# UpdateStairsState
	mScene->mMapBlock->UpdateStairState(tUnit);
}
void Object_Unit_Aladdin::ObjectCheckCollision() {
	mSourceRect.Update(this);
	for (auto &obj : *mScene) {
		if (isRender == true && obj != this) {
			if (isIntersect(
				obj->GetBound(),
				this->GetBound()
			)) {
				obj->ObjectIntersect(this);
			};
		}
	}
}