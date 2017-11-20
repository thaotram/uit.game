#pragma once
#include <d3d9.h>
#include <d3dx9.h>

#include "Unit_Animation.h"
#include "Unit_Transform.h"
#include "Unit_SourceRect.h"

class Unit;

class Unit_Entity {
private:
	D3DXVECTOR2			mPosition;
	Unit_Animation		mAnimation;
	Unit_Transform		mTransform;
	Unit_SourceRect		mSourceRect;
public:
	Unit_Entity();
	void Draw(Unit * pUnit);
	void Update(Unit * pUnit);

	D3DXVECTOR2	    * GetPosition();
	Unit_Animation  * GetAnimation();
	Unit_Transform  * GetTransform();
	Unit_SourceRect * GetSourceRect();
};