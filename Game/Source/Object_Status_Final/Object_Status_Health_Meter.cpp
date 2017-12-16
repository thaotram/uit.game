#include "Object_Status_Health_Meter.h"
#define mAni	mAnimation
#define mPos	mPosition

Object_Status_Health_Meter::Object_Status_Health_Meter() : Object_Status("Status") {
	/// Xét trường hợp health meter nằm ngoài vùng giá trị 1-> 8
	//i = i < 1 ? 1 : (i > 8 ? 8 : i);

	mAni.Set("health_meter_8", 1);
	mAutoNextFrame = true;
}

void Object_Status_Health_Meter::ObjectUpdateEvent(float delay)
{
	string state = "health_meter_" + to_string(Scene::mScene->mBlood);
	if (mAni.GetState() != state)		mAni.Set(state);
	mPos <<Scene::mScene->mCamera.VECTOR2()+ V2{ 66  , 12 };
}
