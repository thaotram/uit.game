#include "Object_Unit_Apple.h"
#define mAni			mAnimation
#define mPos			mPosition
#define	mObjectStore	mScene->oObjectStore
#define tSpeedX	400
//#define tSpeedX	490

#define xx mPos.x()
#define yy mPos.y()

//# Quả táo dùng để ném đi
Object_Unit_Apple::Object_Unit_Apple(float x, float y) : Object_Unit("Aladdin") {
	mPos << V2{ x , y };
	mAni.Set("apple", 1);
	mTimePerFrame = 0.03f;
	mAutoNextFrame = false;
	mIsThrow = false;
}

void Object_Unit_Apple::ObjectUpdateEvent(float dt) {
	if (!mIsThrow) return;
	
	tUnit = RECT{
		(LONG)xx - 3,
		(LONG)yy - 7,
		(LONG)xx + 3,
		(LONG)yy
	};
	tDis = mObjectStore->GetDistance(tUnit, this);

	if(tDis.bottom != 0){
		mPos.x += tSpeedX * dt * (mFlip ? -1 : 1);
		mPos.y = yy + tDis.bottom;
		mPos.Update(dt);
	} else {
		// Chạm đất hoặc quái
		// Hiện tại mới chỉ đụng độ chạm đất...
		// Sẽ phải code thêm phần đụng độ quái khi đã có quái
		mAutoNextFrame = true;
		if(mAni.GetCycleIndex() == 8){
			mIsMarkedDelete = true;
		}
	}
}

void Object_Unit_Apple::ThrowApple(bool pFlip) {
	if (mIsThrow) return;

	mFlip = pFlip;
	mIsThrow = true;
	mAni.SetCycleIndex(2);
}