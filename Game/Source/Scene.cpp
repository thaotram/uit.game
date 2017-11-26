#include "Scene.h"
#include "Unit.h"

//! Private
void Scene::EachUnit(function<void(Unit*)> pEachUnit) {
	for (auto &unit : *this) {
		pEachUnit(unit.second);
	}
}

//! Public
Scene::Scene() {
	mCameraPosition = { 0,0 };
}
Scene::~Scene() {
	EachUnit([=](Unit * pItem) {
		delete pItem;
	});
}

void Scene::Update(float dt) {
	EachUnit([=](Unit * pItem) {
		pItem->Update(dt);
	});
}

void Scene::Draw() {
	EachUnit([=](Unit * pItem) {
		pItem->Draw();
	});
}

void Scene::OnKeyDown(int pKeyCode) {
}

void Scene::OnKeyUp(int pKeyCode) {
}

void Scene::Add(string pName, Unit * pUnit) {
	(*this)[pName] = pUnit;
	pUnit->mScene = this;
	pUnit->AfterAddToScene();
}
