#include "Object.h"

#define mPos mPosition

Object::Object(string pName) : mName(pName) {
	mSpriteHandler = GameGlobal::GetSpriteHandler();

	mScene = Scene::mScene;
	mJson = Object_Json::GetJson(mName);
	mTexture = Object_Texture::GetTexture(mName);

	mCurrentTime = 0;
	mTimePerFrame = 0.06f;

	mIsRender = true;
	mIsUpdate = true;
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
	float xx = mPos.x();
	float yy = mPos.y();
	V2 basepoint = mJson->GetBasePoint(this);
	return RECT{
		(LONG)(xx - basepoint.x),
		(LONG)(yy - basepoint.y),
		(LONG)(xx - basepoint.x + mSourceRect.GetWidth()),
		(LONG)(yy - basepoint.y + mSourceRect.GetHeight())
	};
}