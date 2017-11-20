#pragma once
#include <d3d9.h>
#include <d3dx9.h>

class Unit_Vector2 : public D3DXVECTOR2 {
public:
	Unit_Vector2() :D3DXVECTOR2(0, 0) {};
	Unit_Vector2(float x, float y) :D3DXVECTOR2(x, y) {};
	D3DXVECTOR2 operator * (CONST D3DXVECTOR2& v) const;
	D3DXVECTOR3 V3();
	D3DXVECTOR2 V2();
};
