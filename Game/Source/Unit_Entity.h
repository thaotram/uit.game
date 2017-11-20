#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <map>
#include <functional> 

#include "Unit_Animation.h"
#include "Unit_Transform.h"
#include "Unit_SourceRect.h"
#include "Unit_Vector2.h"

class Unit;

class Unit_Entity {
protected:
	Unit_Vector2		mPosition;
	Unit_Animation		mAnimation;
	Unit_Transform		mTransform;
	Unit_SourceRect		mSourceRect;

public:
	Unit_Entity(Unit_Vector2 pPosition, string pState) {
		mPosition = pPosition;
		mAnimation.SetState(pState);
	};
	void Draw(Unit * pUnit);
	void Update(Unit * pUnit);
	
	Unit_Vector2    * GetPosition();
	Unit_Animation  * GetAnimation();
	Unit_Transform  * GetTransform();
	Unit_SourceRect * GetSourceRect();

	function<void()>  mEndFunction;
};

class Unit_Entities : public map<string, Unit_Entity*> {
public:
	Unit_Entities() {};
	void EachEntity(function<void(Unit_Entity*)> pEachUnit);
	void Draw(Unit * pUnit);
	void Update(Unit * pUnit);
};