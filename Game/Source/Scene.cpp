#include "Scene.h"

//! Private
void Scene::EachUnit(function<void(Unit*)> eachUnit) {
	for (auto &unit : mUnits) {
		eachUnit(unit.second);
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

void Scene::AddChild(string pUnitName, Unit * pUnit) {
	mUnits[pUnitName] = pUnit;
}
void Scene::RemoveChild(string pUnitName) {
	mUnits.erase(pUnitName);
}
Unit * Scene::GetUnit(string pUnitName) {
	return mUnits[pUnitName];
}

inline Unit * Scene::operator[](string pUnitName)
{
	return mUnits[pUnitName];
}
inline Unit * Scene::operator()(string pUnitName)
{
	return mUnits[pUnitName];
}
inline void Scene::operator()(string pUnitName, Unit * pUnit)
{
	mUnits[pUnitName] = pUnit;
}

void Scene::OnKeyDown(int pKeyCode) {}
void Scene::OnKeyUp(int pKeyCode) {}
void Scene::OnMouseDown(float x, float y) {}
