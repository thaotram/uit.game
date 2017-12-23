#include "Object.h"

#define mPos mPosition

Object::Object(string pName) : mName(pName) {
	mSpriteHandler = GameGlobal::GetSpriteHandler();

	mJson = Object_Json::GetJson(mName);
	mTexture = Object_Texture::GetTexture(mName);

	mCurrentTime = 0;
	mTimePerFrame = 0.06f;

	mIsMarkedDelete = false;
	mIsMakeDamage = false;

	mIsFlicker = false;
	mAlwaysOn = false;
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
	bool flip = mTransform.GetFlip();
	float xx = mPos.x();
	float yy = mPos.y();
	V2 basepoint = mJson->GetBasePoint(this);
	return flip ? RECT{
		(LONG)(xx + basepoint.x - mSourceRect.GetWidth()),
		(LONG)(yy - basepoint.y),
		(LONG)(xx + basepoint.x),
		(LONG)(yy - basepoint.y + mSourceRect.GetHeight())
	} : RECT{
		(LONG)(xx - basepoint.x),
		(LONG)(yy - basepoint.y),
		(LONG)(xx - basepoint.x + mSourceRect.GetWidth()),
		(LONG)(yy - basepoint.y + mSourceRect.GetHeight())
	};
}