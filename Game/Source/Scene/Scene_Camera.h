#pragma once
#include "../Utility/Vector_Easing.h"
#include "../../Define.h"

class Scene_Camera : public Vector_Easing {
public:
	Scene_Camera() : Vector_Easing() {};
	void operator=(V2 pDelta);

	RECT GetSourceRect();
};
