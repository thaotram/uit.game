#pragma once
#include <d3d9.h>
#include <d3dx9.h>

#include "../../Define.h"
#include "../GameGlobal.h"
#include "../Utility/Vector.h"
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


	bool				mIsRender;
	bool				mIsUpdate;
	bool				mIsMarkedDelete;
	bool				mIsMakeDamage;

	RECT				tUnit;				// Tọa độ của 4 cạnh so với map lớn
	RECT				tUnitDamage;		// Tọa độ của 4 cạnh so với map lớn
	RECT 				tDis;				// Khoảng cách từ tUnit cho đến 4
	Party				mParty;

	virtual void AfterAddToScene() {};
	void ObjectRender(float delay);

	virtual void ObjectUpdateEvent(float delay) {};
	virtual void ObjectIntersect(Object * pObject) {};
	virtual void ObjectGetDame(Object * pObject) {};
	virtual void ObjectUpdateProperties(float delay) {};
	void		 ObjectDraw(
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