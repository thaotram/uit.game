#include "Scene.h"

//! Private
void Scene::EachUnit(function<void(Unit*)> pEachUnit) {
	for (auto &unit : *this) {
		pEachUnit(unit.second);
	}
}

//! Public
Scene::Scene() {}
Scene::~Scene() {
	EachUnit([=](Unit * item) {
		delete item;
	});
}

void Scene::Update(float dt) {
	EachUnit([=](Unit * item) {
		item->Update(dt);
	});
}

void Scene::Draw() {
	EachUnit([=](Unit * item) {
		item->Draw();
	});
}

void Scene::OnKeyDown(int pKeyCode) {}
void Scene::OnKeyUp(int pKeyCode) {}
void Scene::OnMouseDown(float pX, float pY) {}
