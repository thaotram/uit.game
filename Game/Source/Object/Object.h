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

	Vector		mPosition;
	Object_Animation	mAnimation;
	Object_Transform	mTransform;
	Object_SourceRect	mSourceRect;

	float				mCurrentTime;
	float 				mTimePerFrame;
protected:
	//bool mAutoNextFrame;
	/* Đoạn này viết còn tệ, còn nhập nhằng khi gọi làm AutoNextFrame... */
public:
	Object(string pName);
	~Object() {};
	Scene		 * mScene;
	virtual void AfterAddToScene() {};
	void		 ObjectRender(float delay);
	
	virtual void ObjectUpdateEvent(float delay) {};
	virtual void ObjectUpdateProperties(float delay) {};
	void		 ObjectDraw(
		Object_Transform pTransform,
		Object_SourceRect pSourceRect,
		Vector pPosition
	);

	Object_SourceRect * GetSourceRect() {
		return &mSourceRect;
	}
	Vector * GetPosition() {
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
};