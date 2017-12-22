#include "Object_Screen.h"
#include "../GameDebug.h"

Object_Screen::Object_Screen() : Object("Black") {
	mPosition << V2{ 0,0 };
	mAnimation.Set("black", 1);
}

void Object_Screen::ObjectUpdateProperties(float delay) {
	mTransform.Update(this);
	mSourceRect.Update(this);
}