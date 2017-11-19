#include "Unit.h"

//!Public
// Được gọi chính xác trong hàm Update, không lệ thuộc "dt"
void Unit::BeforeUpdateUnit() {}

Unit::Unit(string pName) : mName(pName) {
	mSpriteHandler = GameGlobal::GetSpriteHandler();
	mTexture = UNIT_TEXTURE::Get("Resources/" + mName + ".png");

	mCurrentTime = 0;
	mTimePerFrame = 0.16f;
	mPosition = { 0, 0, 0 };
	mCenter = { 0, 0, 0 };

	mAnimation.Initialization("Resources/" + mName + ".json");
	Update(0);
}
void Unit::Update(float dt) {
	if (mAnimation.empty()) {
		mAnimation.Initialization("Resources/" + mName + ".json");
	}
	// Update mAnimation
	// mAnimation.Initialization("Resources/" + mName + ".json");
	if (mCurrentTime >= mTimePerFrame) {
		mCurrentTime -= mTimePerFrame;

		BeforeUpdateUnit();
		mAnimation.NextFrame();
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
		&(mPosition * GameGlobal::GetScale()),
		0xFFFFFFFF
	);
}

RECT Unit::GetSourceRect() {
	return mSourceRect;
}
D3DXVECTOR3 Unit::GetPosition() {
	return mPosition;
}

UNIT_ANIMATION * Unit::GetAnimation() {
	return &mAnimation;
}
UNIT_TRANSFORM * Unit::GetTransform() {
	return &mTransform;
}

void Unit::SetPosition(float x, float y, float z) {
	mPosition = { x, y, 0 };
}
RECT Unit::GetBound() {
	return RECT{
		(LONG)(mPosition.x),
		(LONG)(mPosition.y),
		(LONG)(mPosition.x + (mSourceRect.right - mSourceRect.left) * GameGlobal::GetScale()),
		(LONG)(mPosition.y + (mSourceRect.bottom - mSourceRect.top) * GameGlobal::GetScale())
	};
}
