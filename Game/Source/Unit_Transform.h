#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <iostream>

class Unit;

class Transform;
typedef Transform UNIT_TRANSFORM;

class Transform : public D3DXMATRIX {
private:
	bool mFlip;	// Flip
public:
	Transform();
	void operator<< (Unit * p);
	void SetFlip(bool pFlip);
};
