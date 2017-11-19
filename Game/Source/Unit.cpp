#include "Unit.h"

//!Public
// Được gọi chính xác trong hàm Update, không lệ thuộc "dt"
bool Unit::UpdateAnimation() {
	return false;
}

Unit::Unit(string pName) : mName(pName) {
	mSpriteHandler = GameGlobal::GetSpriteHandler();
	mTexture = UNIT_TEXTURE::Get("Resources/" + mName + ".png");

	mCurrentTime = 0;
	mTimePerFrame = 0.16f;
	mPosition = { 0, 0 };
	mCenter = { 0, 0, 0 };

	mAnimation.Initialization("Resources/" + mName + ".json");
	Update(0);
}
void Unit::Update(float dt) {
	if (mAnimation.empty()) {
		mAnimation.Initialization("Resources/" + mName + ".json");
	}
	if (mCurrentTime >= mTimePerFrame) {
		mCurrentTime -= mTimePerFrame;

		if (!UpdateAnimation()) {
			mAnimation++;
		};
		mSourceRect << this;
		mTransform << this;
	}
	else mCurrentTime += dt;
}
void Unit::Draw() {
	mSpriteHandler->SetTransform(&mTransform);
	mSpriteHandler->Draw(
		mTexture,
		&mSourceRect,
		&mCenter,
		&(mPosition.VECTOR3() * GameGlobal::GetScale()),
		0xFFFFFFFF
	);
}

RECT Unit::GetSourceRect() {
	return mSourceRect;
}
VECTOR2 Unit::GetPosition() {
	return mPosition;
}

UNIT_ANIMATION * Unit::GetAnimation() {
	return &mAnimation;
}
UNIT_TRANSFORM * Unit::GetTransform() {
	return &mTransform;
}

void Unit::SetPosition(float x, float y) {
	mPosition = { x, y };
}
RECT Unit::GetBound() {
	return RECT{
		(LONG)(mPosition.x),
		(LONG)(mPosition.y),
		(LONG)(mPosition.x + mSourceRect.GetWidth()),
		(LONG)(mPosition.y + mSourceRect.GetHeight())
	};
}
