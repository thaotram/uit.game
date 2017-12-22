#include "Object_Screen.h"
#include "../GameDebug.h"

Object_Screen::Object_Screen(string pName) : Object(pName) {
	mPosition.x.mType = Type::none;
	mPosition.y.mType = Type::none;
}

void Object_Screen::ObjectUpdateProperties(float delay) {
	mTransform.Update(this);
	mSourceRect.Update(this);
}