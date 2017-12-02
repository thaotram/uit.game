#pragma once
#include "../Utility/Vector_Easing.h"
#include "../../Define.h"

class Scene_Camera : public Vector_Easing {
public:
	RECT GetSourceRect(float delay) {
		return RECT{
			(LONG)(x),
			(LONG)(y),
			(LONG)(x + WIDTH),
			(LONG)(y + HEIGHT)
		};
	}
};
