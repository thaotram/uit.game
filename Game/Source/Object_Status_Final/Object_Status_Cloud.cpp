#include "Object_Status_Cloud.h"
#define mAni	mAnimation
#define mPos	mPosition

Object_Status_Cloud::Object_Status_Cloud(State_Cloud c) : Object_Status("AgrabahMarket_Cloud"){
	mStateCloud = c;
	switch (mStateCloud)
	{
	case 0:
		mAni.Set("sand_1", 1);
		break;
	case 1:
		mAni.Set("sand_2", 1);
		break;
	case 2:
		mAni.Set("sand_3", 1);
		break;
	case 3:
		mAni.Set("sand_4", 1);
		break;
	case 4:
		mAni.Set("sand_5", 1);
		break;
	case 5:
		mAni.Set("cloud_1", 1);
		break;
	case 6:
		mAni.Set("cloud_2", 1);
		break;
	case 7:
		mAni.Set("cloud_3", 1);
		break;
	case 8:
		mAni.Set("cloud_4", 1);
		break;

	}
}

void Object_Status_Cloud::ObjectUpdateEvent(float delay)
{
	mPos << mScene->mCamera.VECTOR2();
}
