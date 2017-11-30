#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "Vector.h"

class Vector_Easing {
private:
	D3DXVECTOR2 mTranslation;
	float		mCurentTime;
	float		mTotalTime;
protected: 
	D3DXVECTOR2 mSelf;
public:
	Vector_Easing();
	void StartTranslation(D3DXVECTOR2 pTranslation, float pTotalTime);
	D3DXVECTOR2 VECTOR2(float delay);
};
