#include "Object_Screen.h"

Object_Screen::Object_Screen() : Object("Black") {
	mPosition << V2{ 0,0 };
	mAnimation.Set("black", 1);
	mTransform.Update(this);
	mSourceRect.Update(this);

	mAlpha = Float_Easing(255, Type::linear, 600);
	mAlpha = 0;
}

void Object_Screen::ObjectUpdateEvent(float delay) {
	mAlpha.Update(delay);
}

void Object_Screen::ObjectDraw(Vector_Easing pPosition, Object_Transform pTransform, Object_SourceRect pSourceRect) {
	mSpriteHandler->SetTransform(&pTransform);
	mSpriteHandler->Draw(
		&*mTexture,
		&pSourceRect,
		NULL,
		&(pPosition.VECTOR() * SCALE).VECTOR3(),
		((int)(mAlpha())) << 24
	);
}