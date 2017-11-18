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

	float							mCurrentTime;	//	Thời gian hiện tại
	float 							mTimePerFrame;
protected:
	virtual void BeforeUpdateUnit();
public:
	Unit(string pName);;
	~Unit() {};

	bool log = false; //? Remove

	void Update(float dt = 0);
	void Draw();

	RECT GetSourceRect();
	D3DXVECTOR3 GetPosition();
	UNIT_ANIMATION * GetAnimation();
	UNIT_TRANSFORM * GetTransform();
	void SetPosition(float x, float y);
	void SetPositionTo(float x, float y);
	RECT GetBound();
};