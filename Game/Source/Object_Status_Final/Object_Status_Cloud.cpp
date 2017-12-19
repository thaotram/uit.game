#include "Object_Status_Cloud.h"
#define mAni	mAnimation
#define mPos	mPosition

Object_Status_Cloud::Object_Status_Cloud(State_Cloud c) : Object_Status("AgrabahMarket_Cloud"){
	mAutoNextFrame = false;
	mStateCloud = c;
	switch (mStateCloud)
	{
	case Sand1:
		mAni.Set("sand_1", 1);
		break;
	case Sand2:
		mAni.Set("sand_2", 1);
		break;
	case Sand3:
		mAni.Set("sand_3", 1);
		break;
	case Sand4:
		mAni.Set("sand_4", 1);
		break;
	case Sand5:
		mAni.Set("sand_5", 1);
		break;
	case Cloud1:
		mAni.Set("cloud_1", 1);
		break;
	case Cloud2:
		mAni.Set("cloud_2", 1);
		break;
	case Cloud3:
		mAni.Set("cloud_3", 1);
		break;
	case Cloud4:
		mAni.Set("cloud_4", 1);
		break;
	}
}

void Object_Status_Cloud::ObjectUpdateEvent(float delay)
{
	mPos << mScene->mCamera.VECTOR2();
}
