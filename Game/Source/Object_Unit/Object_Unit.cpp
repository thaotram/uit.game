#include "Object_Unit.h"
#include "../GameDebug.h"

Object_Unit::Object_Unit(string pName) : Object(pName) {
	mPosition.x.mType = Type::none;
	mPosition.y.mType = Type::gravity;
	mAutoNextFrame = true;
	tUnitDamage = RECT{ 0,0,0,0 };
	mHealthPoint = 1;
}

void Object_Unit::ObjectUpdateProperties(float delay) {
	if (mCurrentTime >= mTimePerFrame) {
		mCurrentTime -= mTimePerFrame;
		//mJson = Object_Json::GetJson(mName);
		if (mAutoNextFrame) mAnimation.NextFrame(this);
	}
	else mCurrentTime += delay;

	if (mAnimation.GetState() == "") return;
	mTransform.Update(this);
	mSourceRect.Update(this);
}