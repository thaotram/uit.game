#pragma once
#include "Scene.h"
#include "../Object_Screen/Object_Screen.h"

Scene* Scene::mScene = NULL;
Scene* Scene::mNextScene = NULL;
Scene* Scene::mBackScene = NULL;
Object_Screen * Scene::oTransparentScreen = NULL;

float Scene::mTimer = 0;
float Scene::mDelay = 0;

//# Status
Object * Scene::mRestartPoint = NULL;
int Scene::mBlood = 7;
int Scene::mApple = 30;
int Scene::mSpendthese = 0;
int Scene::mExtrahealth = 3;
Float_Easing Scene::mScore = *(new Float_Easing(0, Type::linear, 300));

#define UpdateIf(object) if(object) object->ObjectUpdateEvent(delay);
#define RenderIf(object) if(object) object->ObjectRender(delay);

#define alpha oTransparentScreen->mAlpha

void Scene::NextScene(Scene* pNextScene) {
	mNextScene = pNextScene;
	alpha = 255;
}

Scene::Scene() {
	if(!oTransparentScreen) oTransparentScreen = 
		new Object_Screen("Screen", "Black");
}
Scene::~Scene() {
	delete oObjectStore;
	delete oPlayer;
}


void Scene::SceneTranlation(float delay){
	if (mNextScene != NULL) {
		if (alpha() == 255) {
			mBackScene = mScene;
			mScene = mNextScene;
			mNextScene = NULL;
			alpha = 0;
		}
	}
}

void Scene::SceneRender(float delay) {}
void Scene::OnKeyDown(int pKeyCode) {}
void Scene::OnKeyUp(int pKeyCode) {}