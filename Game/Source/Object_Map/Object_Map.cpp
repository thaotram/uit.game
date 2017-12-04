#include "Object_Map.h"

Object_Map::Object_Map(string pName) : Object(pName) {
	mPosition = { 0,0 };
}

void Object_Map::AfterAddToScene() {
	mTransform.Update(this);
}

void Object_Map::ObjectUpdateProperties(float delay) {
	auto c = mScene->mCamera;
	
	mSourceRect = RECT{
		(LONG)(c.x),
		(LONG)(c.y),
		(LONG)(c.x + WIDTH),
		(LONG)(c.y + HEIGHT)
	};
}