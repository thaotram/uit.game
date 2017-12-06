#include "Object_Unit.h"
#include "../GameDebug.h"

Object_Unit::Object_Unit(string pName) : Object(pName) {
	mAutoNextFrame = true;
}

void Object_Unit::AfterAddToScene() {}

void Object_Unit::ObjectUpdateProperties(float delay) {
	mPosition.Update(delay);

	if (mCurrentTime >= mTimePerFrame) {
		mCurrentTime -= mTimePerFrame;
		if(mAutoNextFrame) mAnimation.NextFrame(this);
	}
	else mCurrentTime += delay;

	//GameDebug::Title(mAnimation.GetCycleIndex());
	mTransform.Update(this);
	mSourceRect.Update(this);
}