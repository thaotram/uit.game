#include "Object_Unit_Aladdin.h"
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
#define speedX	200
#define speedY	200

#define state	mAni.GetState()

#define unit	RECT{		\
	(LONG)xx - 15,			\
	(LONG)yy - 50,			\
	(LONG)xx + 15,			\
	(LONG)yy				\
}

Object_Unit_Aladdin::Object_Unit_Aladdin() : Object_Unit("Aladdin") {
	mPos << V2{ 2000, MAP_HEIGHT - 100 };
	mAni.Set("stand", 1);
}

void Object_Unit_Aladdin::ObjectUpdateEvent(float dt) {
	//# Distance
	RECT dis = mBlk->GetDistance(unit);

	isChangeX = isChangeY = true;
	//# Each State
	if (state == "stand") {
		isChangeX = false;
		if (U)			mAni.Set("up", 1);
		ef_(D)			mAni.Set("sit", 1);
		ef_(R || L)		mAni.Set("run", 1);
		ef_(Z) 			mAni.Set("stand_throwapple", 1, "stand", 1);
		ef_(X) 			mAni.Set("stand_cut", 1, "stand", 1);
		ef_(C) 			mAni.Set("stand_jump", 1, "stand", 1);
	}
	ef_(state == "stand_jump") {
		if (mAni.GetCycleIndex() == 1 && mPos.y.mVelocity == 0) {
			mPos.y.mVelocity = -jump;
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
	}
	ef_(state == "up") {
		isChangeX = false;
		if (!U)			mAni.Set("up_to_stand", 1, "stand", 1);
		ef_(U && Z)		mAni.Set("stand_throwapple", 1, "up", 3);
		ef_(U && X)		mAni.Set("up_cut", 1, "up", 3);
		ef_(U && C)		mAni.Set("stand_jump", 1, "stand", 1);
	}
	ef_(state == "up_cut") {
		isChangeX = false;
		if (R || L)		mAni.Set("run", 1);
		ef_(U)			mAni.SetNext("up", 3);
		ef_(D)			mAni.Set("sit", 1);
		else			mAni.SetNext("stand", 1);
	}
	ef_(state == "sit") {
		isChangeX = false;
		if (!D)			mAni.Set("sit_to_stand", 1, "stand", 1);
		ef_(Z)			mAni.Set("sit_throwapple", 1, "sit", 4);
		ef_(X)			mAni.Set("sit_cut", 1, "sit", 4);
		ef_(C)			mAni.Set("stand_jump", 1, "sit", 1);
	}
	ef_(state == "run") {
		if (!L && !R)	mAni.Set("stand", 1);
		if (Z)			0; /// "run_throwapple" - thiếu
		ef_(X)			mAni.Set("run_cut", 1, "run", 9);
		ef_(C)			mAni.Set("run_jump", 1);
	}
	ef_(state == "run_cut") {
		if (!R && !L)	mAni.Set("stand", 1);
	}
	ef_(state == "run_jump") {
		if (mAni.GetCycleIndex() == 1 && mPos.y.mVelocity == 0) {
			mAutoNextFrame = false;
			mPos.y.mVelocity = -jump;
			mAni.SetCycleIndex(1);
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
	}

	//# Climb_vertical
	auto rope = mBlk->GetRope(unit, speedX * dt);
	if (state == "climb_vertical") {
		isChangeX = isChangeY = false;
		mPos.y.mVelocity = 0;
		mPos.y << yy + (D ? 1 : U ? -1 : 0) * speedY * dt;
		mPos.y.Update(0);
	}

	ef_(mPos.y.mVelocity >= 0 && rope.first) {
		mAni.Set("climb_vertical", 1);
	}

	//# Flip
	mTransform.SetFlip(L ? Left : R ? Right : Stand);

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
		min(max(0, mPos.x() - (WIDTH / 2)), MAP_WIDTH - WIDTH),
		min(max(0, mPos.y() - (HEIGHT - 56)), MAP_HEIGHT - HEIGHT)
	};
}