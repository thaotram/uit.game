#include "Object_Unit_Aladdin.h"
#include "../Object_Unit_Final/Object_Unit_Apple.h"
#include "../GameDebug.h"

#define ef_ else if
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
#define	mBlk	mScene->mMapBlock

#define dis		vDistance
#define xx mPos.x()
#define yy mPos.y()

#define jump	350
#define speedY	100

#define state	mAni.GetState()

Object_Unit_Aladdin::Object_Unit_Aladdin() : Object_Unit("Aladdin") {
	mPos << V2{ 200, 600 };
	//mPos << V2{ 1900, 400 };
	mAni.Set("stand", 1);
}

void Object_Unit_Aladdin::ObjectUpdateEvent(float dt) {
	//# Flip
	mTransform.SetFlip(R ? Right : L ? Left : Stand);

	//# Global
	RECT unit = RECT{
		(LONG)xx - 15,
		(LONG)yy - 55,
		(LONG)xx + 15,
		(LONG)yy
	};

	float speedX = 200;
	RECT dis = mBlk->GetDistance(unit);
	pair<bool, RECT> rope = mBlk->GetRope(unit, speedX * dt);
	pair<bool, RECT> bar = mBlk->GetWoodenBar(unit, mPos.y.mVelocity * dt);
	isChangeX = isChangeY = true;

	if (bar.first) {
		int a = 1;

		auto p = mBlk->GetWoodenBar(unit, mPos.y.mVelocity * dt);
	}
	//# Each State
	if (state == "") {
		mAni.Set("stand", 1);
	}
	ef_(state == "stand") {
		mAutoNextFrame = true;
		mTimePerFrame = 0.06f;
		isChangeX = false;
		if (U)						mAni.Set("up", 1);
		ef_(D)						mAni.Set("sit", 1);
		ef_(R || L)					mAni.Set("run", 1);
		ef_(Z) {
			mScene->Add("2", new Object_Unit_Apple(xx - 12, yy - 55, mTransform.GetFlip()));
			mAni.Set("stand_throwapple", 1, "stand", 1);
		}
		ef_(X) 						mAni.Set("stand_cut", 1, "stand", 1);
		ef_(C && dis.bottom == 0)	mAni.Set("stand_jump", 1, "stand", 1) && mPos.y.SetVelocity(-jump);
	}
	ef_(state == "stand_throwapple") {
		mTimePerFrame = 0.06f;
		isChangeX = false;
		if (mAni.GetCycleIndex() == 4) {
			((Object_Unit*)((*mScene)["2"]))->mAutoNextFrame = true;
		}
	}
	ef_(state == "stand_jump") {
		mTimePerFrame = 0.06f;
		if (mAni.GetNextState() == "stand_jump") mAni.SetNext("stand", 1);
		if (mAni.GetCycleIndex() == 1 && mPos.y.mVelocity == 0 && mAni.GetNextState() != "stand") {
			mAutoNextFrame = false;
			mAni.SetCycleIndex(1);
		}
		ef_(
			dis.bottom < 20
			&& mPos.y.mVelocity >= 0
			&& !mAutoNextFrame
		) {
			mAutoNextFrame = true;
			mAni.SetCycleIndex(11);
		}
		ef_(mAutoNextFrame && mPos.y.mVelocity == 0) {
			mAni.Next();
		}
		ef_(mAutoNextFrame)						0;
		ef_(mPos.y.mVelocity <= 0.7 * -jump)	mAni.SetCycleIndex(2);
		ef_(mPos.y.mVelocity <= 0.3 * -jump)	mAni.SetCycleIndex(3);
		ef_(mPos.y.mVelocity <= 0)				mAni.SetCycleIndex(4);
		ef_(mPos.y.mVelocity <= 0.3 * +jump)	mAni.SetCycleIndex(5);
		ef_(mPos.y.mVelocity <= 0.5 * +jump)	mAni.SetCycleIndex(6);
		ef_(mPos.y.mVelocity <= 0.7 * +jump)	mAni.SetCycleIndex(7);
		ef_(mPos.y.mVelocity <= 0.9 * +jump)	mAni.SetCycleIndex(8);
		ef_(mPos.y.mVelocity <= 1.0 * +jump)	mAni.SetCycleIndex(9);
		ef_(mPos.y.mVelocity <= 1.1 * +jump)	mAni.SetCycleIndex(9);
		ef_(mPos.y.mVelocity <= 1.2 * +jump)	mAni.SetCycleIndex(10);

		if (Z) {
			mScene->Add("2", new Object_Unit_Apple(xx - 12, yy - 55, mTransform.GetFlip()));
			mAni.Set("jump_throwapple", 1, "stand_jump", 4);
		}
		if (X)			mAni.Set("jump_cut", 1, "stand_jump", 4);
	}
	ef_(state == "jump_throwapple") {
		mTimePerFrame = 0.03f;
		isChangeX = false;
		if (mAni.GetCycleIndex() == 4) {
			((Object_Unit*)((*mScene)["2"]))->mAutoNextFrame = true;
		}
	}
	ef_(state == "jump_cut") {
		mTimePerFrame = 0.03f;
		mAutoNextFrame = true;
	}
	ef_(state == "up") {
		mTimePerFrame = 0.06f;
		isChangeX = false;
		if (!U)			mAni.Set("up_to_stand", 1, "stand", 1);
		ef_(U && Z)		mAni.Set("stand_throwapple", 1, "up", 3);
		ef_(U && X)		mAni.Set("up_cut", 1, "up", 3);
		ef_(U && C) 	mAni.Set("stand_jump", 1, "stand", 1) && mPos.y.SetVelocity(-jump);
	}
	ef_(state == "up_cut") {
		mTimePerFrame = 0.06f;
		isChangeX = false;
		if (R || L)		mAni.Set("run", 1);
		ef_(U)			mAni.SetNext("up", 3);
		ef_(D)			mAni.Set("sit", 1);
		else			mAni.SetNext("stand", 1);
	}
	ef_(state == "sit") {
		mTimePerFrame = 0.06f;
		isChangeX = false;
		if (!D)			mAni.Set("sit_to_stand", 1, "stand", 1);
		ef_(Z) {
			mScene->Add("2", new Object_Unit_Apple(xx + 5, yy - 27, mTransform.GetFlip()));
			mAni.Set("sit_throwapple", 1, "sit", 4);
		}
		ef_(X)			mAni.Set("sit_cut", 1, "sit", 4);
		ef_(C)			mAni.Set("stand_jump", 1, "sit", 1) && mPos.y.SetVelocity(-jump);
	}
	ef_(state == "sit_to_stand") {
		mTimePerFrame = 0.06f;
		isChangeX = false;
		mAutoNextFrame = true;
	}
	ef_(state == "sit_cut") {
		mTimePerFrame = 0.06f;
		isChangeX = false;
	}
	ef_(state == "sit_throwapple") {
		mTimePerFrame = 0.06f;
		isChangeX = false;
		if (mAni.GetCycleIndex() == 3) {
			((Object_Unit*)((*mScene)["2"]))->mAutoNextFrame = true;
		}
	}
	ef_(state == "run") {
		mTimePerFrame = 0.06f;
		if (!L && !R)	mAni.Set("stand", 1);
		if (Z)			0; /// "run_throwapple" - thiếu
		ef_(X)			mAni.Set("run_cut", 1, "run", 9);
		ef_(C)			mAni.Set("run_jump", 1) && mPos.y.SetVelocity(-jump);
	}
	ef_(state == "run_cut") {
		mTimePerFrame = 0.06f;
		if (!R && !L)	mAni.Set("stand", 1);
	}
	ef_(state == "run_jump") {
		mTimePerFrame = 0.06f;
		if (mAni.GetCycleIndex() == 1 && mPos.y.mVelocity == -jump) {
			mAutoNextFrame = false;
			// mPos.y.mVelocity = -jump;
			mAni.SetCycleIndex(1);
		}
		ef_(mPos.y.mVelocity == 0 && dis.bottom == 0) {
			mAni.Set("stand", 1);
		}
		ef_(
			dis.bottom < 20
			&& mPos.y.mVelocity > 0
			&& !mAutoNextFrame
		) {
			mAutoNextFrame = true;
			if (R || L)	mAni.SetCycleIndex(11) && mAni.SetNext("run", 11);
			else		mAni.SetCycleIndex(7) && mAni.SetNext("stand", 1);
		}
		ef_(mAutoNextFrame && mPos.y.mVelocity == 0) {
			mAni.Next();
		}
		ef_(mAutoNextFrame)							0;	/// Ngưng lại ///
		ef_(mPos.y.mVelocity <= 0.90 * -jump)		mAni.SetCycleIndex(2);
		ef_(mPos.y.mVelocity <= 0.60 * -jump)		mAni.SetCycleIndex(3);
		ef_(mPos.y.mVelocity <= 0.30 * -jump)		mAni.SetCycleIndex(4);
		ef_(mPos.y.mVelocity <= 0)					mAni.SetCycleIndex(5);
		ef_(mPos.y.mVelocity <= 0.50 * +jump)		mAni.SetCycleIndex(5);
		ef_(mPos.y.mVelocity <= 0.90 * +jump)		mAni.SetCycleIndex(6);
		//if (Z) mAni.Set("jump_thowapple", 1, "run_jump", 1);
		if (X) mAni.Set("jump_cut", 1, "run_jump", 1);
	}
	ef_(state == "climb_still") {
		mTimePerFrame = 0.06f;
		mAutoNextFrame = true;
		isChangeX = isChangeY = false;
		if (L || R)				mAni.Set("climb_horizontal", 1);
		ef_(C) {
			mAutoNextFrame = false;
			mAni.Set("stand_jump", 1);
		}
	}
	ef_(state == "climb_vertical") {
		mTimePerFrame = 0.06f;
		mPos.y.mVelocity = 0;
		mAutoNextFrame = false;
		isChangeX = isChangeY = false;
		mCurrentTime += dt;
		auto cycleIndex = mAni.GetCycleIndex();

		if (mCurrentTime >= mTimePerFrame) {
			mCurrentTime -= mTimePerFrame;
			float	deltaY = 0;
			if (U)	deltaY = -min(speedY * mTimePerFrame, abs(unit.top - rope.second.top));
			ef_(D)	deltaY = +min(speedY * mTimePerFrame, abs(unit.bottom - rope.second.bottom));

			mAni.SetCycleIndex(
				(deltaY == +speedY * mTimePerFrame) ? (cycleIndex > 3 ? cycleIndex - 1 : 10) :
				(deltaY == -speedY * mTimePerFrame) ? (cycleIndex < 10 ? cycleIndex + 1 : 3) :
				cycleIndex
			);
			mPos.y << yy + deltaY;
		}

		if (Z)		mAni.Set("climb_throwapple", 1, "climb_vertical", cycleIndex);
		ef_(X)		mAni.Set("climb_cut", 1, "climb_vertical", cycleIndex);
		ef_(C)		mAni.Set("climb_jump", 1) && mPos.y.SetVelocity(-jump);
	}
	ef_(state == "climb_horizontal") {
		mTimePerFrame = 0.06f;
		speedX = 80;
		mAutoNextFrame = true;
		isChangeY = false;
		if (!L && !R)			mAni.Set("climb_still", 1);
		ef_(C) {
			mAutoNextFrame = false;
			mAni.Set("stand_jump", 1);
		}
	}
	ef_(state == "climb_throwapple") {
		mTimePerFrame = 0.06f;
		mAutoNextFrame = true;
		isChangeX = isChangeY = false;
	}
	ef_(state == "climb_jump") {
		mTimePerFrame = 0.06f;
		mAutoNextFrame = false;
		if (dis.bottom == 0)						mAni.Set("stand", 1);
		ef_(mPos.y.mVelocity <= 0.9 * -jump)		mAni.SetCycleIndex(1);
		ef_(mPos.y.mVelocity <= 0.2 * -jump)		mAni.SetCycleIndex(2);
		ef_(mPos.y.mVelocity <= 0.5 * +jump)		mAni.SetCycleIndex(3);
		ef_(mPos.y.mVelocity <= 0.4 * +jump)		mAni.SetCycleIndex(4);
		ef_(mPos.y.mVelocity <= 0.5 * +jump)		mAni.SetCycleIndex(5);
		ef_(mPos.y.mVelocity <= 0.6 * +jump)		mAni.SetCycleIndex(6);
		ef_(mPos.y.mVelocity <= 0.7 * +jump)		mAni.SetCycleIndex(7);
		ef_(mPos.y.mVelocity <= 0.8 * +jump)		mAni.SetCycleIndex(8);
		ef_(mPos.y.mVelocity <= 0.9 * +jump)		mAni.SetCycleIndex(9);
		ef_(mPos.y.mVelocity <= 1.0 * +jump)		mAni.Set("stand_jump", 4, "stand", 1);
	}
	ef_(state == "climb_cut") {
		mTimePerFrame = 0.06f;
		mAutoNextFrame = true;
		isChangeX = isChangeY = false;
	}

	if (mPos.y.mVelocity >= -0.2 * jump && rope.first) {
		if (state != "climb_vertical" &&
			state != "climb_cut" &&
			state != "climb_throwapple") {
			isChangeX = false;
			mCurrentTime = 0;
			mPos.x << (rope.second.left + rope.second.right) / 2.f;
			mAni.Set("climb_vertical", 1);
		}
	}
	ef_(bar.first) {
		if (state != "climb_still" &&
			state != "climb_horizontal" &&
			state != "climb_cut" &&
			state != "climb_throwapple" &&
			state != "stand_jump") {
			mPos.y << bar.second.top + 87;
			mAni.Set("climb_still", 1);
		}
	}
	else {
		//GameDebug::Title("false");
	}

	//GameDebug::Title(mAni.GetCycleIndex());

	//# Position
	mPos.x += !isChangeX ? 0
		: R ? +min(speedX * dt, dis.right)
		: L ? -min(speedX * dt, dis.left)
		: 0;
	mPos.x.Update(dt);
	dis = mBlk->GetDistance(unit);
	mPos.y = !isChangeY ? yy :
		yy + dis.bottom;
	mPos.y.Update(dt);

	//# Camera
	mCam = V2{
		min(max(0, xx - (WIDTH / 2)), MAP_WIDTH - WIDTH),
		min(max(0, yy - (HEIGHT - 56)), MAP_HEIGHT - HEIGHT)
	};
}