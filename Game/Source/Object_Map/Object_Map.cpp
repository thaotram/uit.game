#include "Object_Map.h"

Object_Map::Object_Map(string pName) : Object(pName) {
	mPosition = { 0,0 };
}

void Object_Map::AfterAddToScene() {
	mTransform.Update(this);
}

void Object_Map::ObjectUpdateProperties(float delay) {
	mSourceRect = mScene->mCamera.RECT( V2{ WIDTH, HEIGHT } );
}