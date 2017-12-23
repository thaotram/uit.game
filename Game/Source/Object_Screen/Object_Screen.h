#ifndef Object_Screen_Included
#define Object_Screen_Included

#pragma once
#include "../../Define.h"
#include "../Object/Object.h"
#include "../Utility/Float_Easing.h"

class Object_Screen final : public Object {
public:
	Object_Screen();
	~Object_Screen() {};
	// [0,100], 100 = hiện toàn bộ / đen toàn bộ
	Float_Easing mAlpha;

	void ObjectUpdateEvent(float delay);
	void ObjectDraw(
		Vector_Easing pPosition,
		Object_Transform pTransform,
		Object_SourceRect pSourceRect
	);
};

#endif // !Object_Screen_Included