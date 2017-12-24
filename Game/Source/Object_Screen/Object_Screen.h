#ifndef Object_Screen_Included
#define Object_Screen_Included

#pragma once
#include "../../Define.h"
#include "../GameGlobal.h"
#include "../Object/Object.h"
#include "../Utility/Float_Easing.h"

class Object_Screen final : public Object {
public:
	Object_Screen(string pName, string pState);
	~Object_Screen() {};

	Float_Easing mAlpha;	// [0,100], 100 = hiện toàn bộ / đen toàn bộ

	void ObjectUpdateEvent(float delay);
	void ObjectDraw(
		Vector_Easing pPosition,
		Object_Transform pTransform,
		Object_SourceRect pSourceRect
	);
};

#endif // !Object_Screen_Included