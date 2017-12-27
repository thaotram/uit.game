#pragma once
#include "../Object_Unit/Object_Unit.h"
#include "../Object_Unit_Final/Object_Unit_Apple.h"
#include "../Scene/Scene.h"

class Object_Unit_Aladdin final : public Object_Unit {
private:
	GameSound* mHighWord;
	GameSound* mAladdinHurt;
	GameSound* mObjectThrow;
	GameSound* mAladdinBurn;
	GameSound* mRestartPoint;

	//# Tạo sẵn các biến để tái sử dụng trong tính toán (không cần cấp phát lại bộ nhớ)
	bool tIsChangeX, tIsChangeY;
	bool tIsThrowApple;
	bool isPlay;
	float tSpeedX, tSpeedY, tJump;
	float tIsPull;

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
	float cTime;

	void ObjectUpdateEvent(float dt);
	void ObjectEachState();
	void ObjectAfterEachState();
	void ObjectIntersect(Object * pObject);
	void ObjectIntersectStar(Object * pObject);
};