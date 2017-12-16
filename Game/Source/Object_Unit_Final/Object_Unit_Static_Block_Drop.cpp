#include "Object_Unit_Static_Block_Drop.h"
#include "../Object_Unit_Final/Object_Unit_Aladdin.h"
#define mAni	mAnimation
#define mPos	mPosition
void Object_Unit_Static_Block_Drop::NewBlock(){
	mTimeCount = 0;
	isDrop = false;
	mPos << V2{ mX , mY };
	mAni.SetCycleIndex(1);
}
Object_Unit_Static_Block_Drop::Object_Unit_Static_Block_Drop(RECT u)
	: Object_Unit("Item"), mX((float)(u.left)), mY((float)(u.top)) {
	mAni.Set("blockdrop");
	mAutoNextFrame = false;
	NewBlock();
}

void Object_Unit_Static_Block_Drop::ObjectUpdateEvent(float dt) {
	mPos.Update(dt);
	if (mPos.y() >= mY + 40) {
		mAni.SetCycleIndex(2);
	}
	if (mAni.GetCycleIndex() == 2) {
		mTimeCount += dt;
		if (mTimeCount >= 1.f) {
			NewBlock();
		}
	}
}

void Object_Unit_Static_Block_Drop::ObjectIntersect(Object * pObject){
	if (!isDrop) {
		if (dynamic_cast<Object_Unit_Aladdin *>(pObject)) {
			auto unit = (Object_Unit_Aladdin *)(pObject);
			if (unit->tDis.bottom == 0) {
				isDrop = true;
				mPosition.y += 40;
			}
		}
		GameDebug::Title("true");
	}
}