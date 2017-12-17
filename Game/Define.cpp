#include "Define.h"

bool isIntersect(RECT a, RECT b) {
	return
		a.left < b.right &&
		a.right > b.left &&
		a.top <= b.bottom &&
		a.bottom >= b.top;
}