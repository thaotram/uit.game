#pragma once
#include "Scene.h"
#include "../Object_Screen/Object_Screen.h"

Scene* Scene::mScene = NULL;
Scene* Scene::mNextScene = NULL;
Scene* Scene::mBackScene = NULL;

Object_Screen* Scene::oTransparentScreen = new Object_Screen();

float Scene::mTimer = 0;
float Scene::mDelay = 0;

//# Status
int Scene::mBlood = 7;
int Scene::mApple = 0;
int Scene::mSpendthese = 0;
int Scene::mExtrahealth = 0;
Float_Easing Scene::mScore = *(new Float_Easing(0, Type::linear, 300));

#define UpdateIf(object) if(object) object->ObjectUpdateEvent(delay);
#define RenderIf(object) if(object) object->ObjectRender(delay);

void Scene::ReplaceScene(Scene* pScene) {
	mDelay = 1.f;
	mTimer = 0;
	mNextScene = pScene;
	oTransparentScreen->mAlpha = 255;
}

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
	//# Replace Scene
	// if(mDelay != 0){
	//     mTime += delay;
	//     if(mTime > mDelay){
	//         mDelay = 0;
	//         mScene = mNextScene;
	//     }
	//     return;
	// }

	//# Update Easing
	Scene::mScore.Update(delay);
	oTransparentScreen->ObjectUpdateEvent(delay);

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

	oTransparentScreen->ObjectRender(delay);
}

void Scene::OnKeyDown(int pKeyCode) {}
void Scene::OnKeyUp(int pKeyCode) {}