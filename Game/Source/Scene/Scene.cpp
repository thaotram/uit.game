#include "Scene.h"

Scene * Scene::mScene = NULL;

//! Static Public
void Scene::ReplaceScene(Scene * pScene) {
	mScene = pScene;
}

//! Public
Scene::Scene() {
	mBlood = 7;
	mApple = 0;
	mSpendthese = 0;
	mExtrahealth = 0;
	//mScore.mType = Type::linear;
	//mScore = 0;
	//mScore.mVelocity = 300;
}
Scene::~Scene() {
	delete oObjectStore;
	delete oPlayer;
	delete oMapBack;
	delete oMapFront;

	delete oApple;
	delete oN_Apple_t;
	delete oN_Apple_u;

	delete oSpendthese;
	delete oNspendthese;

	delete oLife;
	delete oNLife;

	delete oMagicLamp;
	delete oHealthMeter;

}

#define isRender	obj->mIsRender
#define isUpdate	obj->mIsUpdate
void Scene::SceneRender(float delay) {
	//# Update
	oPlayer->ObjectUpdateEvent(delay);
	oObjectStore->ObjectUpdateEvent(delay);
	oMapBack->ObjectUpdateEvent(delay);
	oMapFront->ObjectUpdateEvent(delay);

	oApple->ObjectUpdateEvent(delay);
	oN_Apple_t->ObjectUpdateEvent(delay);
	oN_Apple_u->ObjectUpdateEvent(delay);

	oSpendthese->ObjectUpdateEvent(delay);
	oNspendthese->ObjectUpdateEvent(delay);

	oLife->ObjectUpdateEvent(delay);
	oNLife->ObjectUpdateEvent(delay);

	oMagicLamp->ObjectUpdateEvent(delay);
	oHealthMeter->ObjectUpdateEvent(delay);

	//# Remove item in RemoveList 
	oObjectStore->ObjectRemoveMarkedDelete();

	//# Render
	oMapBack->ObjectRender(delay);
	oObjectStore->ObjectRender(delay);
	oPlayer->ObjectRender(delay);
	oMapFront->ObjectRender(delay);

	oApple->ObjectRender(delay);
	oN_Apple_t->ObjectRender(delay);
	oN_Apple_u->ObjectRender(delay);

	oSpendthese->ObjectRender(delay);
	oNspendthese->ObjectRender(delay);

	oLife->ObjectRender(delay);
	oNLife->ObjectRender(delay);


	oMagicLamp->ObjectRender(delay);
	oHealthMeter->ObjectRender(delay);

	//mScore.Update(delay);
}

void Scene::OnKeyDown(int pKeyCode) {}
void Scene::OnKeyUp(int pKeyCode) {}

//void Scene::AddToRemoveList(Object * pObject) {
//	mRemoveList.push_back(pObject);
//}