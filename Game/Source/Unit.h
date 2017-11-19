#pragma once
#include <d3d9.h>
#include <d3dx9.h>

#include "GameGlobal.h"

#include "Unit_Texture.h"
#include "Unit_Animation.h"
#include "Unit_Transform.h"
#include "Unit_SourceRect.h"

class VECTOR2 : public D3DXVECTOR2 {
public:
	VECTOR2(bool flip) :D3DXVECTOR2(
		(float)(flip ? -1 : 1), 1
	) {}
	D3DXVECTOR2 operator * (CONST D3DXVECTOR2& v) const {
		return D3DXVECTOR2(x * v.x, y * v.y);
	}
};

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
	D3DXVECTOR2						mPosition;

	float							mCurrentTime;	//	Thời gian hiện tại
	float 							mTimePerFrame;
protected:
	virtual void BeforeUpdateUnit();
public:
	Unit(string pName);;
	~Unit() {};

	void Update(float dt = 0);
	void Draw();

	RECT GetSourceRect();
	D3DXVECTOR2 GetPosition();
	UNIT_ANIMATION * GetAnimation();
	//UNIT_TRANSFORM * GetTransform();
	void SetPosition(float x, float y);
	RECT GetBound();
};