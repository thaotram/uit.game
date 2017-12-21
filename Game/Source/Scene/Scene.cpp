#include "Scene.h"
Scene* Scene::mScene = NULL;

#define UpdateIf(object) if(object) object->ObjectUpdateEvent(delay);
#define RenderIf(object) if(object) object->ObjectRender(delay);


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
	//oPlater 
    oBackground = new Scene_Background();
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
	UpdateIf(oPlayer);
	UpdateIf(oObjectStore);
    UpdateIf(oMapBack);
    UpdateIf(oMapFront);
	UpdateIf(oStatus);
    UpdateIf(oBackground);

    //# Remove item in RemoveList
    oObjectStore->ObjectRemoveMarkedDelete();

	//# Render
	RenderIf(oBackground);
	RenderIf(oMapBack);
	RenderIf(oObjectStore);
	RenderIf(oPlayer);
	RenderIf(oMapFront);
	RenderIf(oStatus);
}

void Scene::OnKeyDown(int pKeyCode) {}
void Scene::OnKeyUp(int pKeyCode) {}