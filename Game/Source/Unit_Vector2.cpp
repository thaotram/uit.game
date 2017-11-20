#include "Unit_Vector2.h"

D3DXVECTOR2 Unit_Vector2::operator*(CONST D3DXVECTOR2 & v) const
{
	return D3DXVECTOR2(x * v.x, y * v.y);
}

D3DXVECTOR3 Unit_Vector2::V3() {
	return D3DXVECTOR3(x, y, 0);
}

D3DXVECTOR2 Unit_Vector2::V2() {
	return D3DXVECTOR2(x, y);
}
