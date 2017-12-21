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

	oStatus = new Scene_Status();
    oBackground = new Scene_Background();
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
}

void Scene::SceneRender(float delay) {
    //# Update Easing
	mScore.Update(delay);
    
    //# Update Event
    oBackground->ObjectUpdateEvent(delay);
	oPlayer->ObjectUpdateEvent(delay);
    oObjectStore->ObjectUpdateEvent(delay);
    oMapBack->ObjectUpdateEvent(delay);
	if(oMapFront) oMapFront->ObjectUpdateEvent(delay);
	oStatus->ObjectUpdateEvent(delay);

    //# Remove item in RemoveList
    oObjectStore->ObjectRemoveMarkedDelete();

	//# Render
    oBackground->ObjectRender(delay);
    oMapBack->ObjectRender(delay);
    oObjectStore->ObjectRender(delay);
    oPlayer->ObjectRender(delay);
    if(oMapFront) oMapFront->ObjectRender(delay);
	oStatus->ObjectRender(delay);
}

void Scene::OnKeyDown(int pKeyCode) {}
void Scene::OnKeyUp(int pKeyCode) {}