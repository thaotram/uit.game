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
	mScore.mType = Type::linear;
	mScore = 0;
	mScore.mVelocity = 300;
}
Scene::~Scene() {
	for (auto &tUnit : *this) {
		delete tUnit;
	}
}

#define margin		100
#define isRender	obj->mIsRender
#define isUpdate	obj->mIsUpdate
void Scene::SceneRender(float delay) {
	//# Update
	oPlayer->ObjectUpdateEvent(delay);
	oObjectStore->ObjectUpdateEvent(delay);
	oMapBack->ObjectUpdateEvent(delay);
	oMapFront->ObjectUpdateEvent(delay);
	
	//# Render
	oMapBack->ObjectRender(delay);
	oObjectStore->ObjectRender(delay);
	oPlayer->ObjectRender(delay);
	oMapFront->ObjectRender(delay);

	mScore.Update(delay);
}

void Scene::OnKeyDown(int pKeyCode) {}
void Scene::OnKeyUp(int pKeyCode) {}

list<Object *>::iterator Scene::Add(list<Object *>::iterator pIt, Object * pObject) {
	pObject->AfterAddToScene();
	return insert(pIt, pObject);
}
list<Object *>::iterator Scene::Add(Object * pObject) {
	return Add(end(), pObject);
}

void Scene::Add(list<Object*>::iterator pIt, Object * pObject, list<Object*>::iterator & pItOut) {
	pItOut = Add(pIt, pObject);
}
void Scene::Add(Object * pObject, list<Object*>::iterator & pItOut) {
	pItOut = Add(pObject);
}

void Scene::AddToRemoveList(Object * pObject) {
	mRemoveList.push_back(pObject);
}