#include "Object_Unit_Static_Restart_Point.h"
#define mAni	mAnimation
#define mPos	mPosition
Object_Unit_Static_Restart_Point::Object_Unit_Static_Restart_Point(RECT u) : Object_Unit("Item") {
	mPos.x << (float)(u.left);
	mPos.y << (float)(u.top);
	mAni.Set("restartpoint", 1);
	mAutoNextFrame = false;
	mSourceRect.Update(this);
	tUnit = GetBound();
	mAlwaysOn = true;
	mRect = u;
	mSound = new GameSound(L"Sound/SFX/Continue Point.wav");
}

void Object_Unit_Static_Restart_Point::ObjectUpdateEvent(float dt)
{
}

void Object_Unit_Static_Restart_Point::ObjectIntersect(Object * pObject)
{
	mAutoNextFrame = true;
	if (Scene::mRestartPoint != this) {
		Scene::mRestartPoint = this;
		mSound->Play();
	}
}
