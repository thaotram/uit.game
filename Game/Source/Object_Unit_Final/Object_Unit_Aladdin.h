#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../Object_Unit_Final/Object_Unit_Apple.h"
#include "../Scene/Scene.h"

class Object_Unit_Aladdin final : public Object_Unit {
private:
	//# Tạo sẵn các biến để tái sử dụng trong tính toán (không cần cấp phát lại bộ nhớ)
	bool tIsChangeX, tIsChangeY;
	float tSpeedX, tSpeedY, tJump, tDt;
	RECT tDis;
	RECT tUnit;
	pair<bool, RECT> tRope, tBar;
	
	list<Object *>::iterator itThrowApple;
public:
	Object_Unit_Aladdin();
	~Object_Unit_Aladdin() {};

	void ObjectUpdateEvent(float dt);
	void ObjectEachState();
	void ObjectAfterEachState();
	void ObjectCheckCollision();
};