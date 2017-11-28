﻿#include "Object.h"
#include "../Scene/Scene.h"
#include "../../Define.h"

Object::Object(string pName) : mName(pName) {
	mSpriteHandler = GameGlobal::GetSpriteHandler();

	mJson = Object_Json::GetJson(mName);
	mTexture = Object_Texture::GetTexture(mName);

	mCurrentTime = 0;
	mTimePerFrame = 0.01f;
}

void Object::ObjectDraw(Object_Transform pTransform, Object_SourceRect pSourceRect, Object_Vector2 pPosition) {
	mSpriteHandler->SetTransform(&pTransform);
	mSpriteHandler->Draw(
		&*mTexture,
		&pSourceRect,
		NULL,
		&(pPosition * SCALE).VECTOR3(),
		0xFFFFFFFF
	);
}