#include "Object_Screen.h"
#include "../GameDebug.h"

Object_Screen::Object_Screen() : Object("Black") {
	mPosition << V2{ 0,0 };
	mAnimation.Set("black", 1);
	mTransform.Update(this);
	mSourceRect.Update(this);

	mAlpha = Float_Easing(100, Type::linear, 300);
	mAlpha = 0;
}

void Object_Screen::ObjectUpdateEvent(float delay) {
	mAlpha.Update(delay);
}

void Object_Screen::ObjectDraw(Vector_Easing pPosition, Object_Transform pTransform, Object_SourceRect pSourceRect) {
	//mSpriteHandler->SetTransform(&pTransform);
	//mSpriteHandler->Draw(
	//	&*mTexture,
	//	&pSourceRect,
	//	NULL,
	//	&(pPosition.VECTOR() * SCALE).VECTOR3(),
	//	((int)(mAlpha() / 100 * 255)) << 24
	//);
}