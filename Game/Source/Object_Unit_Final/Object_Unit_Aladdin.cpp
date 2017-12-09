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

#define mAni mAnimation
#define mPos mPosition

#define jump 350
#define speed 200

#define state mAni.GetState()

//#define velocity

#define ground mScene->mMapBlock->GetGround(mPos.x() + leftOrRight * speed * dt, mPos.y())
#define height ground - mPos.y()
#define moveLeftOrRight leftOrRight = R ? 1 : (L ? -1 : 0)

Object_Unit_Aladdin::Object_Unit_Aladdin() : Object_Unit("Aladdin") {
	mPos << V2{ WIDTH / 2, MAP_HEIGHT - 100 };
	mPos.x.mType = Type::none;
	mPos.y.mType = Type::gravity;
	mAni.Set("stand", 1);

	velocity = &(mPos.y.mVelocity);
}

void Object_Unit_Aladdin::ObjectUpdateEvent(float dt) {
	//# Camera
	mScene->mCamera = mPos.VECTOR2() - V2{ WIDTH / 2, HEIGHT - 56 };

	//# Left or Right
	leftOrRight = 0;

	//# Flip
	if (L) mTransform.SetFlip(true);
	ef_(R) mTransform.SetFlip(false);

	//# Each State
	if (state == "stand") {
		if (U)			mAni.Set("up", 1);
		ef_(D)			mAni.Set("sit", 1);
		ef_(R || L)		mAni.Set("run", 1);
		ef_(Z) 			mAni.Set("stand_throwapple", 1, "stand", 1);
		ef_(X) 			mAni.Set("stand_cut", 1, "stand", 1);
		ef_(C) 			mAni.Set("stand_jump", 1, "stand", 1);
	}
	ef_(state == "stand_jump") {
		moveLeftOrRight;			//# Move Left or Right

		if (mAni.GetCycleIndex() == 1 && *velocity == 0) {
			*velocity = -jump;
			mAutoNextFrame = false;
			mAni.SetCycleIndex(1);
		}
		ef_(
			height < 20
			&& *velocity >= 0
			&& !mAutoNextFrame
		) {
			mAutoNextFrame = true;
			mAni.SetCycleIndex(11);
		}
		ef_(mAutoNextFrame && *velocity == 0) {
			mAni.Next();
		}
		ef_(mAutoNextFrame)				0;
		ef_(*velocity <= 0.65 * -jump)	mAni.SetCycleIndex(2);
		ef_(*velocity <= 0.30 * -jump)	mAni.SetCycleIndex(3);
		ef_(*velocity <= 0)				mAni.SetCycleIndex(4);
		ef_(*velocity <= 0.30 * +jump)	mAni.SetCycleIndex(5);
		ef_(*velocity <= 0.50 * +jump)	mAni.SetCycleIndex(6);
		ef_(*velocity <= 0.70 * +jump)	mAni.SetCycleIndex(7);
		ef_(*velocity <= 0.90 * +jump)	mAni.SetCycleIndex(8);
		ef_(*velocity <= 1.00 * +jump)	mAni.SetCycleIndex(9);
		ef_(*velocity <= 1.10 * +jump)	mAni.SetCycleIndex(9);
		ef_(*velocity <= 1.20 * +jump)	mAni.SetCycleIndex(10);
	}
	ef_(state == "up") {
		if (!U)			mAni.Set("up_to_stand", 1, "stand", 1);
		ef_(U && Z)		mAni.Set("stand_throwapple", 1, "up", 3);
		ef_(U && X)		mAni.Set("up_cut", 1, "up", 3);
		ef_(U && C)		mAni.Set("stand_jump", 1, "stand", 1);
	}
	ef_(state == "up_cut") {
		if (U)			mAni.SetNext("up", 3);
		ef_(!U)			mAni.SetNext("stand", 1);

		if (D)			mAni.Set("sit", 1);
		ef_(R || L)		mAni.Set("run", 1);
	}
	ef_(state == "sit") {
		if (!D)			mAni.Set("sit_to_stand", 1, "stand", 1);
		ef_(D && Z)		mAni.Set("sit_throwapple", 1, "sit", 4);
		ef_(D && X) 	mAni.Set("sit_cut", 1, "sit", 4);
		ef_(D && C)		mAni.Set("stand_jump", 1, "sit", 1);
	}
	ef_(state == "run") {
		if (!R && !L)	mAni.Set("stand", 1);
		else moveLeftOrRight;		//# Move Left or Right

		if (Z) {} 		//- mAni.Set("run_throwapple", 1, "run", 4);
		ef_(X)			mAni.Set("run_cut", 1, "run", 9);
		ef_(C)			mAni.Set("run_jump", 1);
	}
	ef_(state == "run_cut") {
		if (!R && !L)	mAni.Set("stand", 1);
		else moveLeftOrRight;		//# Move Left or Right
	}
	ef_(state == "run_jump") {
		moveLeftOrRight;			//# Move Left or Right
		if (mAni.GetCycleIndex() == 1 && *velocity == 0) {
			mAutoNextFrame = false;
			mPos.y.mVelocity = -jump;
			mAni.SetCycleIndex(1);
		}
		ef_(
			height < 20
			&& *velocity > 0
			&& !mAutoNextFrame
		) {
			mAutoNextFrame = true;
			if (R || L)	mAni.SetCycleIndex(11) && mAni.SetNext("run", 11);	// run
			else		mAni.SetCycleIndex(7) && mAni.SetNext("stand", 1);
		}
		ef_(mAutoNextFrame && *velocity == 0) {
			mAni.Next();
		}
		ef_(mAutoNextFrame)					0;
		ef_(*velocity <= 0.90 * -jump)		mAni.SetCycleIndex(2);
		ef_(*velocity <= 0.60 * -jump)		mAni.SetCycleIndex(3);
		ef_(*velocity <= 0.30 * -jump)		mAni.SetCycleIndex(4);
		ef_(*velocity <= 0)					mAni.SetCycleIndex(5);
		ef_(*velocity <= 0.50 * +jump)		mAni.SetCycleIndex(5);
		ef_(*velocity <= 0.90 * +jump)		mAni.SetCycleIndex(6);
	}
}

void Object_Unit_Aladdin::ObjectUpdatePosition(float dt) {
	//# Position
	mPos.x += leftOrRight * speed * dt;			//# FIX
	mPos.y = ground;
	mPos.Update(dt);
}