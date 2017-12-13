#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <functional>

#include "../GameGlobal.h"

#include "Object_Json.h"
#include "Object_Texture.h"

#include "../Utility/Vector.h"
#include "Object_Animation.h"
#include "Object_Transform.h"
#include "Object_SourceRect.h"

#include "../Scene/Scene.h"

class Object
{
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

	Scene		 * mScene;

	virtual void AfterAddToScene() {};
			void ObjectRender(float delay);
	
	virtual void ObjectUpdateEvent(float delay) {};
	virtual void ObjectUpdateProperties(float delay) {};
	void		 ObjectDraw(
		Vector_Easing pPosition,
		Object_Transform pTransform,
		Object_SourceRect pSourceRect
	);

	Object_SourceRect * GetSourceRect() {
		return &mSourceRect;
	}
	Vector_Easing * GetPosition() {
		return &mPosition;
	}
	Object_Animation * GetAnimation() {
		return &mAnimation;
	}
	Object_Transform * GetTransform() {
		return &mTransform;
	}
	Object_Json * GetJson() {
		return mJson;
	}

	RECT GetBound();
};