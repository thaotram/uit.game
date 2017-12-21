#include "Scene.h"
Scene* Scene::mScene = NULL;

int Scene::mBlood = 7;
int Scene::mApple = 0;
int Scene::mSpendthese = 0;
int Scene::mExtrahealth = 0;
Float_Easing Scene::mScore = Float_Easing(123);
//Scene::mScore->
//mScore.mType = Type::linear;
//mScore.mVelocity = 300;

#define UpdateIf(object) if(object) object->ObjectUpdateEvent(delay);
#define RenderIf(object) if(object) object->ObjectRender(delay);


//! Static Public
void Scene::ReplaceScene(Scene* pScene) {
    delete mScene;
    mScene = pScene;
}

//! Public
Scene::Scene() {
	oStatus = new Scene_Status();
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