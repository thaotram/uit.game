#pragma once
#include "../../Define.h"
#include "../Object/Object.h"
#include "../Utility/Float_Easing.h"

class Object_Screen final : public Object {
public:
	Object_Screen();
	~Object_Screen() {};
	Float_Easing mAlpha;

	void ObjectUpdateEvent(float delay);
	void ObjectDraw(
		Vector_Easing pPosition,
		Object_Transform pTransform,
		Object_SourceRect pSourceRect
	);
};
