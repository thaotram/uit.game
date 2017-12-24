#include "Object_Screen.h"

Object_Screen::Object_Screen(string pName, string pState) : Object(pName){
	mPosition << V2{ 0,0 };
	mAnimation.Set(pState, 1);
	mAlpha = Float_Easing(0, Type::linear, 600);
}

void Object_Screen::ObjectUpdateEvent(float delay) {
	mAlpha.Update(delay);
	mTransform.Update(this);
	mSourceRect.Update(this);
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