#include "Vector_Easing.h"
#include "../GameDebug.h"
#include <math.h>

void Vector_Easing::operator+=(V2 pDelta) {
	x += pDelta.x;
	y += pDelta.y;
}
void Vector_Easing::operator-=(V2 pDelta) {
	x -= pDelta.x;
	y -= pDelta.y;
}
void Vector_Easing::operator=(V2 pLast){
	x = pLast.x;
	y = pLast.y;
}

// Gán giá trị mặc định
void Vector_Easing::operator<<(V2 pVector) {
	x << pVector.x;
	y << pVector.y;
}
void Vector_Easing::Update(float delay) {
	x.Update(delay);
	y.Update(delay);
}

V2 Vector_Easing::VECTOR2() {
	return V2(
		x(),
		y()
	);
}
Vector Vector_Easing::VECTOR() {
	return Vector(
		x(),
		y()
	);
}

Float_Easing * Vector_Easing::GetX() {
	return &x;
}
Float_Easing * Vector_Easing::GetY() {
	return &y;
}
