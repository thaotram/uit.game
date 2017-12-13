#include "Object_Status.h"
#include "../GameDebug.h"

Object_Status::Object_Status(string pName) : Object(pName) {
	mPosition.x.mType = Type::none;
	mPosition.y.mType = Type::none;
	mAutoNextFrame = false;
}

void Object_Status::ObjectUpdateProperties(float delay) {
	if (mCurrentTime >= mTimePerFrame) {
		mCurrentTime -= mTimePerFrame;
		if (mAutoNextFrame) mAnimation.NextFrame(this);
	}
	else mCurrentTime += delay;

	mTransform.Update(this);
	mSourceRect.Update(this);
}