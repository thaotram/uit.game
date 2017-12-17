#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../Object_Unit_Final/Object_Unit_Apple.h"
#include "../Scene/Scene.h"

class Object_Unit_Aladdin final : public Object_Unit {
private:
	//# Tạo sẵn các biến để tái sử dụng trong tính toán (không cần cấp phát lại bộ nhớ)
	bool tIsChangeX, tIsChangeY;
	float tSpeedX, tSpeedY, tJump, tDt;
	pair<bool, RECT> 
		tRope, 
		tBar, 
		tDropBlock;
	
	list<Object *>::iterator itThrowApple;
public:
	Object_Unit_Aladdin();
	~Object_Unit_Aladdin() {};

	bool mIsOnDropBlock;

	void ObjectUpdateEvent(float dt);
	void ObjectEachState();
	void ObjectAfterEachState();
	void ObjectCheckCollision();
};