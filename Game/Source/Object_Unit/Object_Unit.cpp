#include "Object_Unit.h"
#include "../GameDebug.h"

Object_Unit::Object_Unit(string pName) : Object(pName) {
	mAutoNextFrame = true;
}

void Object_Unit::AfterAddToScene() {}

void Object_Unit::ObjectUpdateProperties(float delay) {
	if (mCurrentTime >= mTimePerFrame) {
		mCurrentTime -= mTimePerFrame;
		if(mAutoNextFrame) mAnimation.NextFrame(this);
	}
	else mCurrentTime += delay;

	GameDebug::Title(mAnimation.GetFrameIndex(this	));
	mPosition.Update(delay);
	mTransform.Update(this);
	mSourceRect.Update(this);
}