#include "Scene.h"
#include "../Object_Status_Final/Object_Status_Apple.h"
#include "../Object_Status_Final/Object_Status_Life.h"
#include "../Object_Status_Final/Object_Status_Health_Meter.h"
#include "../Object_Status_Final/Object_Status_Magic_Lamp.h"
#include "../Object_Status_Final/Object_Status_Number_S.h"
#include "../Object_Status_Final/Object_Status_Number_L.h"
#include "../Object_Status_Final/Object_Status_Spendthese.h"
#include "../Object_Status_Final/Object_Status_Cloud.h"

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

	oApple = new Object_Status_Apple();
	oN_Apple_u = new Object_Status_Number_S(296, 200, S_Apple_Ones);
	oN_Apple_t = new Object_Status_Number_S(288, 200, S_Apple_Tens);

	oSpendthese = new Object_Status_Spendthese();
	oNspendthese = new Object_Status_Number_S(253, 200, S_Spendthese);

	oLife = new Object_Status_Life();
	oNLife = new Object_Status_Number_S(42, 200, S_Life);

	oMagicLamp = new Object_Status_Magic_Lamp();
	oHealthMeter = new Object_Status_Health_Meter();

	oScore_1 = new Object_Status_Number_L(275, 20, L_Score_Ones);
	oScore_2 = new Object_Status_Number_L(258, 20, L_Score_Tens);
	oScore_3 = new Object_Status_Number_L(241, 20, L_Score_Hundreds);
	oScore_4 = new Object_Status_Number_L(224, 20, L_Score_Thousand);

	oSand_1 = new Object_Status_Cloud(Sand1);
	oSand_2 = new Object_Status_Cloud(Sand2);
	oSand_3 = new Object_Status_Cloud(Sand3);
	oSand_4 = new Object_Status_Cloud(Sand4);
	oSand_5 = new Object_Status_Cloud(Sand5);
	oCloud_1 = new Object_Status_Cloud(Cloud1);
	oCloud_2 = new Object_Status_Cloud(Cloud2);
	oCloud_3 = new Object_Status_Cloud(Cloud3);
	oCloud_4 = new Object_Status_Cloud(Cloud4);
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
	oSand_1->ObjectRender(delay);
	oSand_2->ObjectRender(delay);
	oSand_3->ObjectRender(delay);
	oSand_4->ObjectRender(delay);
	oSand_5->ObjectRender(delay);
	oCloud_1->ObjectRender(delay);
	oCloud_2->ObjectRender(delay);
	oCloud_3->ObjectRender(delay);
	oCloud_4->ObjectRender(delay);

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

	oMagicLamp->ObjectRender(delay);
	oHealthMeter->ObjectRender(delay);

	mScore.Update(delay);
}

void Scene::OnKeyDown(int pKeyCode) {}
void Scene::OnKeyUp(int pKeyCode) {}