#include "Object_Unit.h"

Object_Unit::Object_Unit(string pName) : Object(pName) {}

void Object_Unit::AfterAddToScene() {}

void Object_Unit::ObjectUpdateProperties(float delay) {
	// mTimePerFrame = 0.08f
	if (mCurrentTime >= mTimePerFrame) {
		mCurrentTime -= mTimePerFrame;
		mAnimation.NextFrame(this);
	}
	else mCurrentTime += delay;
	mTransform.Update(this);
	mSourceRect.Update(this);
}