﻿#include "Object.h"
#include "../Scene/Scene.h"
#include "../../Define.h"

#define mPos mPosition

Object::Object(string pName) : mName(pName) {
	mSpriteHandler = GameGlobal::GetSpriteHandler();

	mJson = Object_Json::GetJson(mName);
	mTexture = Object_Texture::GetTexture(mName);

	mCurrentTime = 0;
	mTimePerFrame = 0.06f;
}
void Object::ObjectRender(float delay) {
	ObjectUpdateProperties(delay);
	ObjectDraw(mPosition, mTransform, mSourceRect);
}
void Object::ObjectDraw(Vector_Easing pPosition, Object_Transform pTransform, Object_SourceRect pSourceRect) {
	mSpriteHandler->SetTransform(&pTransform);
	mSpriteHandler->Draw(
		&*mTexture,
		&pSourceRect,
		NULL,
		&(pPosition.VECTOR() * SCALE).VECTOR3(),
		0xFFFFFFFF
	);
}

RECT Object::GetBound() {
	return RECT{
		(LONG)mPos.x(),
		(LONG)mPos.y(),
		(LONG)mPos.x(),
		(LONG)mPos.y()
	};
}