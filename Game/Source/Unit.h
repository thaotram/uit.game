#pragma once
#include <d3d9.h>
#include <d3dx9.h>

#include "GameGlobal.h"

#include "Unit_Texture.h"
#include "Unit_Animation.h"
#include "Unit_Transform.h"
#include "Unit_SourceRect.h"


class Unit
{
protected:
	string							mName;
	LPD3DXSPRITE					mSpriteHandler;
	LPDIRECT3DTEXTURE9				mTexture;
	UNIT_ANIMATION					mAnimation;
	UNIT_TRANSFORM					mTransform;
	RECT							mSourceRect;

	D3DXVECTOR3						mCenter;
	D3DXVECTOR3						mPosition;

	float mCurrentTime, mTimePerFrame;
public:
	Unit(string pName) : mName(pName) {
		mSpriteHandler = GameGlobal::GetSpriteHandler();
		mTexture = UNIT_TEXTURE::Get("Resources/" + mName + ".png");

		mTimePerFrame = 0.2f;
		mPosition = { 0, 0, 0 };
		Update();
	};
	~Unit() {};

	//? Remove
	bool log = false;

	void Update(float dt = 0) {
		if (mAnimation.empty()) {
			mAnimation.Initialization("Resources/" + mName + ".json");
		}
		if (mCurrentTime >= mTimePerFrame) {
			mCurrentTime = 0;
			
			//!? Update Animation
			mAnimation.Initialization("Resources/" + mName + ".json");
			
			//? Remove
			if (log) {
				//mAnimation.Log();
				RECT _ = GetBound();
				GameDebug::Title(
					to_string(_.left) + " " +
					to_string(_.top) + " " +
					to_string(_.right) + " " +
					to_string(_.bottom)
				);
			}
			{
				//!? Thao tác cập nhật frame - BEGIN
				mAnimation.NextFrame();
				mSourceRect = mAnimation.GetFrame();
				mTransform.UpdateFrom(mSourceRect, mPosition, mAnimation.GetTransition());
			}
		}
		else mCurrentTime += dt;
	}

	void Draw() {
		mSpriteHandler->SetTransform(&mTransform);
		mSpriteHandler->Draw(
			mTexture,
			&mSourceRect,
			&mCenter,
			&mPosition,
			0xFFFFFFFF
		);
	}

	RECT GetSourceRect() {
		return mSourceRect;
	}
	D3DXVECTOR3 GetPosition() {
		return mPosition;
	}
	UNIT_ANIMATION GetAnimation() {
		return mAnimation;
	}
	void SetPosition(float x, float y) {
		mPosition = { x, y, 0 };
	}
	RECT GetBound() {
		return RECT{
			(LONG)(mPosition.x),
			(LONG)(mPosition.y),
			(LONG)(mPosition.x + (mSourceRect.right - mSourceRect.left) * GameGlobal::GetScale()),
			(LONG)(mPosition.y + (mSourceRect.bottom - mSourceRect.top) * GameGlobal::GetScale())
		};
	}
};