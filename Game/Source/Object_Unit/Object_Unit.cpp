#include "Object_Unit.h"
#include "../GameDebug.h"

Object_Unit::Object_Unit(string pName) : Object(pName) {
	mPosition.x.mType = Type::none;
	mPosition.y.mType = Type::gravity;
	mAutoNextFrame = true;
}

void Object_Unit::AfterAddToScene() {}

void Object_Unit::ObjectUpdateProperties(float delay) {
	if (mCurrentTime >= mTimePerFrame) {
		mCurrentTime -= mTimePerFrame;
		if (mAutoNextFrame) mAnimation.NextFrame(this);
	}
	else mCurrentTime += delay;

	mTransform.Update(this);
	mSourceRect.Update(this);
}