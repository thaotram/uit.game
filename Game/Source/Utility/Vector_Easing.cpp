#include "Vector_Easing.h"
#include "../GameDebug.h"
#include <math.h>

#define D GameDebug::Title

void Vector_Easing::operator+=(V2 pDelta) {
	x += pDelta.x;
	y += pDelta.y;
}

void Vector_Easing::operator-=(V2 pDelta) {
	x -= pDelta.x;
	y -= pDelta.y;
}

void Vector_Easing::operator=(V2 pNext){
	x = pNext.x;
	y = pNext.y;
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