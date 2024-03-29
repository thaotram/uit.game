#include "Object_Unit_Static_Abubonus.h"
#define mAni	mAnimation
#define mPos	mPosition
Object_Unit_Static_Abubonus::Object_Unit_Static_Abubonus(RECT u) : Object_Unit("Item") {
	mPos.x << (float)(u.left);
	mPos.y << (float)(u.top);
	
	mAni.Set("abubonus", 1);
	mAutoNextFrame = true;
	tUnit = GetBound();
	mSound = new GameSound(L"Sound/SFX/Wow!.wav");
}

void Object_Unit_Static_Abubonus::ObjectUpdateEvent(float delay) {
}

void Object_Unit_Static_Abubonus::ObjectIntersect(Object * pObject)
{
	Scene::mScore += 250;
	mIsMarkedDelete = true;
	mSound->Play();
}