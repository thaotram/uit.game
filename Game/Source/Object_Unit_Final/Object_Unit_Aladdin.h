#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../Object_Unit_Final/Object_Unit_Apple.h"
#include "../Scene/Scene.h"

class Object_Unit_Aladdin final : public Object_Unit {
private:
	//# Tạo sẵn các biến để tái sử dụng trong tính toán (không cần cấp phát lại bộ nhớ)
	bool tIsChangeX, tIsChangeY;
	bool tIsThrowApple;
	float tSpeedX, tSpeedY, tJump;

	pair<bool, RECT>
		tBar,
		tRope,
		tDropBlock;
	pair<bool, pair<RECT, Object *> *> tStick;
	pair<bool, pair<RECT, Object *> *> tCamel;
public:
	Object_Unit_Aladdin(float x, float y);
	~Object_Unit_Aladdin() {};

	bool mIsOnDropBlock;

	void ObjectUpdateEvent(float dt);
	void ObjectEachState();
	void ObjectAfterEachState();
	void ObjectCheckCollisionWithEnemy();
	void ObjectGetDame(Object * pObject);
};