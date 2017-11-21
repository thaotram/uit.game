#include "Unit.h"

Unit::Unit(string pName) : mName(pName) {
	mSpriteHandler = GameGlobal::GetSpriteHandler();
	mJson << mName;
	mTexture << mName;

	mCurrentTime = 0;
	mTimePerFrame = 0.1f;
}
void Unit::Update(float dt) {
	if (mCurrentTime >= mTimePerFrame) {
		//mCurrentTime -= mTimePerFrame;
		mCurrentTime = 0;
		if (UpdateUnit()) return;
		mEntities.Update(this);
	}
	else mCurrentTime += dt;
}
void Unit::Draw() {
	if (DrawUnit()) return;
	mEntities.Draw(this);
}

void Unit::Draw(Unit_Transform pTransform, Unit_SourceRect pSourceRect, Unit_Vector2 pPosition)
{
	mSpriteHandler->SetTransform(&pTransform);
	mSpriteHandler->Draw(
		&mTexture,
		&pSourceRect,
		NULL,
		&(pPosition.V3() * GameGlobal::GetScale()),
		0xFFFFFFFF
	);
}

void Unit::Set(Unit_Entity * pEntity)
{
	mEntities["default"] = pEntity;
}

Unit_Entity * Unit::Get()
{
	return mEntities["default"];
}

Unit_Json * Unit::GetJson()
{
	return &mJson;
}
