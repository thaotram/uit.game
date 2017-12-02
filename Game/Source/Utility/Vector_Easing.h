#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "Vector.h"
#include "../../Define.h"
#define V2 D3DXVECTOR2

class Vector_Easing : public Vector {
private:
	V2 mNow, mNext, mBack;
public:
	Vector_Easing() {}
	Vector_Easing(V2 pVector) {
	}

	void operator<< (V2 pVector) {
		mNow = pVector;
		mNext = pVector;
	}
	void operator= (V2 pNext) {
		mNext = pNext;
	}
	void Update(float delay);
};