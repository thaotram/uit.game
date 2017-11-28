#include "Object_Vector2.h"

D3DXVECTOR3 Object_Vector2::VECTOR3() {
	return D3DXVECTOR3(x, y, 0);
}
RECT Object_Vector2::BOUND(const D3DXVECTOR2 & v) {
	return RECT{
		(LONG)(x),
		(LONG)(y),
		(LONG)(x + v.x),
		(LONG)(y + v.y)
	};
}
D3DXVECTOR2 Object_Vector2::VECTOR2() {
	return D3DXVECTOR2(x, y);
}

Object_Vector2 Object_Vector2::operator*(const float v) const {
	return Object_Vector2(x * v, y * v);
}
Object_Vector2 Object_Vector2::operator*(const D3DXVECTOR2 &v) const {
	return Object_Vector2(x * v.x, y * v.y);
}
Object_Vector2 Object_Vector2::operator+(const Object_Vector2 &v) const {
	return Object_Vector2(x + v.x, y + v.y);
}
Object_Vector2 Object_Vector2::operator+(const D3DXVECTOR2 &v) const {
	return Object_Vector2(x + v.x, y + v.y);
}
Object_Vector2 Object_Vector2::operator-(const Object_Vector2 &v) const {
	return Object_Vector2(x - v.x, y - v.y);
}
Object_Vector2 Object_Vector2::operator-(const D3DXVECTOR2 &v) const {
	return Object_Vector2(x - v.x, y - v.y);
}