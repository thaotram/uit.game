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
	mScore << 0;
	mScore.mType = Type::linear;
	mScore.mVelocity = 300;
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

	delete oScore_1;
	delete oScore_2;
	delete oScore_3;
	delete oScore_4;

	delete oSand_1;
	delete oSand_2;
	delete oSand_3;
	delete oSand_4;
	delete oSand_5;
	delete oCloud_1;
	delete oCloud_2;
	delete oCloud_3;
	delete oCloud_4;

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

	oScore_1->ObjectUpdateEvent(delay);
	oScore_2->ObjectUpdateEvent(delay);
	oScore_3->ObjectUpdateEvent(delay);
	oScore_4->ObjectUpdateEvent(delay);

	oSand_1->ObjectUpdateEvent(delay);
	oSand_2->ObjectUpdateEvent(delay);
	oSand_3->ObjectUpdateEvent(delay);
	oSand_4->ObjectUpdateEvent(delay);
	oSand_5->ObjectUpdateEvent(delay);
	oCloud_1->ObjectUpdateEvent(delay);
	oCloud_2->ObjectUpdateEvent(delay);
	oCloud_3->ObjectUpdateEvent(delay);
	oCloud_4->ObjectUpdateEvent(delay);

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

	oScore_1->ObjectRender(delay);
	oScore_2->ObjectRender(delay);
	oScore_3->ObjectRender(delay);
	oScore_4->ObjectRender(delay);

	oSand_1->ObjectRender(delay);
	oSand_2->ObjectRender(delay);
	oSand_3->ObjectRender(delay);
	oSand_4->ObjectRender(delay);
	oSand_5->ObjectRender(delay);
	oCloud_1->ObjectRender(delay);
	oCloud_2->ObjectRender(delay);
	oCloud_3->ObjectRender(delay);
	oCloud_4->ObjectRender(delay);

	oMagicLamp->ObjectRender(delay);
	oHealthMeter->ObjectRender(delay);

	mScore.Update(delay);
}

void Scene::OnKeyDown(int pKeyCode) {}
void Scene::OnKeyUp(int pKeyCode) {}