#include "Scene.h"
#include "../Object/Object.h"

//! Private
void Scene::EachUnit(function<void(Object*)> pEachUnit) {
	for (auto &unit : *this) {
		pEachUnit(unit.second);
	}
}

//! Public
Scene::Scene() {
	mCameraPosition = { 0,0 };
}
Scene::~Scene() {
	EachUnit([=](Object * pObject) {
		delete pObject;
	});
}

void Scene::SceneRender(float delay) {
	EachUnit([=](Object * pObject) {
		pObject->ObjectRender(delay);
	});
}

void Scene::OnKeyDown(int pKeyCode) {}
void Scene::OnKeyUp(int pKeyCode) {}

void Scene::Add(string pName, Object * pObject) {
	(*this)[pName] = pObject;
	pObject->mScene = this;
	pObject->AfterAddToScene();
}
