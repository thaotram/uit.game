#ifndef Object_Included
#define Object_Included

#pragma once
#include <d3d9.h>
#include <d3dx9.h>

#include "../../Define.h"
#include "../GameGlobal.h"
#include "../Utility/Vector_Easing.h"
#include "../Scene/Scene.h"

#include "Object_Json.h"
#include "Object_Texture.h"

#include "Object_Animation.h"
#include "Object_Transform.h"
#include "Object_SourceRect.h"

enum Party {
	Friend,
	Enemy
};

class Object {
protected:
	string				mName;
	LPD3DXSPRITE		mSpriteHandler;
	Object_Json			* mJson;
	Object_Texture		* mTexture;

	Vector_Easing		mPosition;
	Object_Animation	mAnimation;
	Object_Transform	mTransform;
	Object_SourceRect	mSourceRect;

	float				mCurrentTime;
	float 				mTimePerFrame;
public:
	Object(string pName);
	~Object() {};

	int					tCount;
	int					tFlickerPerSecond;
	bool				tIsDraw;
	bool				mIsFlicker;
	bool				mAlwaysOn;
	bool				mIsMarkedDelete;
	bool				mIsMakeDamage;

	Party				mParty;
	RECT				tUnit;				// Tọa độ của 4 cạnh so với map lớn
	RECT				tUnitDamage;		// Tọa độ của 4 cạnh so với map lớn
	RECT 				tDis;				// Khoảng cách từ tUnit cho đến 4

	virtual void AfterAddToScene() {};
	void ObjectRender(float delay);

	virtual void ObjectUpdateEvent(float delay) {};
	virtual void ObjectIntersect(Object * pObject) {};
	virtual void ObjectUpdateProperties(float delay) {};
	virtual void ObjectDraw(
		Vector_Easing pPosition,
		Object_Transform pTransform,
		Object_SourceRect pSourceRect
	);

	Object_SourceRect	* GetSourceRect() {
		return &mSourceRect;
	}
	Vector_Easing		* GetPosition() {
		return &mPosition;
	}
	Object_Animation	* GetAnimation() {
		return &mAnimation;
	}
	Object_Transform	* GetTransform() {
		return &mTransform;
	}
	Object_Json			* GetJson() {
		return mJson;
	}
	RECT GetBound();
};

#endif