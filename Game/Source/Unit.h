#pragma once
#include <d3d9.h>
#include <d3dx9.h>

#include "GameGlobal.h"

#include "Unit_Entity.h"

#include "Unit_Json.h"
#include "Unit_Texture.h"
#include "Unit_Animation.h"
#include "Unit_Transform.h"
#include "Unit_SourceRect.h"

class Unit_Entities;
class Unit_Entity;

class Unit
{
protected:
	string							mName;
	LPD3DXSPRITE					mSpriteHandler;
	Unit_Json						mJson;
	Unit_Texture					mTexture;

	Unit_Entities					mEntities;

	float							mCurrentTime;
	float 							mTimePerFrame;
protected:
	virtual bool UpdateUnit() { return false; };
	virtual bool DrawUnit() { return false; };
public:
	Unit(string pName);
	~Unit() {};

	void Update(float dt);
	void Draw();
	void Draw(
		Unit_Transform pTransform,
		Unit_SourceRect pSourceRect,
		Unit_Vector2 pPosition
	);

	void Set(Unit_Entity *);
	Unit_Entity * Get();

	Unit_Json * GetJson();
};