#include "Scene.h"
Scene* Scene::mScene = NULL;

//! Static Public
void Scene::ReplaceScene(Scene* pScene) {
    delete mScene;
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

    //# Status

	// oStatus = new Scene_Status();

    // oSand_1 = new Object_Status_Cloud(Sand1);
    // oSand_2 = new Object_Status_Cloud(Sand2);
    // oSand_3 = new Object_Status_Cloud(Sand3);
    // oSand_4 = new Object_Status_Cloud(Sand4);
    // oSand_5 = new Object_Status_Cloud(Sand5);
    // oCloud_1 = new Object_Status_Cloud(Cloud1);
    // oCloud_2 = new Object_Status_Cloud(Cloud2);
    // oCloud_3 = new Object_Status_Cloud(Cloud3);
    // oCloud_4 = new Object_Status_Cloud(Cloud4);
}
Scene::~Scene() {
    delete oObjectStore;
    delete oPlayer;
    delete oMapBack;
    delete oMapFront;

    // delete oApple;
    // delete oN_Apple_t;
    // delete oN_Apple_u;

    // delete oSpendthese;
    // delete oNspendthese;

    // delete oLife;
    // delete oNLife;

    // delete oMagicLamp;
    // delete oHealthMeter;

    // delete oScore_1;
    // delete oScore_2;
    // delete oScore_3;
    // delete oScore_4;

    // delete oSand_1;
    // delete oSand_2;
    // delete oSand_3;
    // delete oSand_4;
    // delete oSand_5;
    // delete oCloud_1;
    // delete oCloud_2;
    // delete oCloud_3;
    // delete oCloud_4;
}

void Scene::SceneRender(float delay) {
    //# Update
	mScore.Update(delay);
    
	oPlayer->ObjectUpdateEvent(delay);
    oObjectStore->ObjectUpdateEvent(delay);
    oMapBack->ObjectUpdateEvent(delay);
    oMapFront->ObjectUpdateEvent(delay);
	// oStatus->ObjectUpdateEvent(delay);

    // oSand_1->ObjectUpdateEvent(delay);
    // oSand_2->ObjectUpdateEvent(delay);
    // oSand_3->ObjectUpdateEvent(delay);
    // oSand_4->ObjectUpdateEvent(delay);
    // oSand_5->ObjectUpdateEvent(delay);
    // oCloud_1->ObjectUpdateEvent(delay);
    // oCloud_2->ObjectUpdateEvent(delay);
    // oCloud_3->ObjectUpdateEvent(delay);
    // oCloud_4->ObjectUpdateEvent(delay);

    //# Remove item in RemoveList
    oObjectStore->ObjectRemoveMarkedDelete();

	//# Render
    // oSand_1->ObjectRender(delay);
    // oSand_2->ObjectRender(delay);
    // oSand_3->ObjectRender(delay);
    // oSand_4->ObjectRender(delay);
    // oSand_5->ObjectRender(delay);
    // oCloud_1->ObjectRender(delay);
    // oCloud_2->ObjectRender(delay);
    // oCloud_3->ObjectRender(delay);
    // oCloud_4->ObjectRender(delay);

    oMapBack->ObjectRender(delay);
    oObjectStore->ObjectRender(delay);
    oPlayer->ObjectRender(delay);
    oMapFront->ObjectRender(delay);
	// oStatus->ObjectRender(delay);
}

void Scene::OnKeyDown(int pKeyCode) {}
void Scene::OnKeyUp(int pKeyCode) {}