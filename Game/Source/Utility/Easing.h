#pragma once
#include <d3d9.h>
#include <d3dx9.h>

class Easing : public D3DXVECTOR2 {
public:
	float		mCurentTime;
	bool		mAnimating;
	D3DXVECTOR2 mTranslation;

	void StartTranslation(D3DXVECTOR2 pTranslation, float pTime);
	void UpdateFromTranslation(float delay);
};
