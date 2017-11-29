#pragma once
#include <d3d9.h>
#include <d3dx9.h>

class VECTOR : public D3DXVECTOR2 {
public:
	VECTOR() :D3DXVECTOR2(0, 0) {};
	VECTOR(float x, float y) :D3DXVECTOR2(x, y) {};
	VECTOR operator* (const D3DXVECTOR2& v) const;
	VECTOR operator* (const float v) const;
	VECTOR operator+ (const VECTOR& v) const;
	VECTOR operator+ (const D3DXVECTOR2& v) const;
	VECTOR operator- (const VECTOR& v) const;
	VECTOR operator- (const D3DXVECTOR2& v) const;
	D3DXVECTOR2 VECTOR2();
	D3DXVECTOR3 VECTOR3();
};
