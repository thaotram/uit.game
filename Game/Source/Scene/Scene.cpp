#include "Scene.h"
#include "../Object/Object.h"
#include "../Object_Unit/Object_Unit.h"

Scene * Scene::mCurrentScene = NULL;

//! Static Public
void Scene::ReplaceScene(Scene * pScene) {
	mCurrentScene = pScene;
}

Scene * Scene::GetCurrentScene() {
	return mCurrentScene;
}

//! Public
Scene::Scene() {}
Scene::~Scene() {
	for (auto &unit : *this) {
		delete unit.second;
	}
}

void Scene::SceneRender(float delay) {
	for (auto &unit : *this) {
		//if (dynamic_cast<Object_Unit *>(pObject)) {
		//	auto bb = pObject->GetBound();
		//	if (bb.left < mCamera.x + WIDTH &&
		//		bb.right > mCamera.x &&
		//		bb.top < mCamera.y + HEIGHT &&
		//		bb.bottom > mCamera.y) {
		//		pObject->ObjectUpdateEvent(delay);
		//	}
		//}
		//else {
		//}
		unit.second->ObjectUpdateEvent(delay);
	}
	for (auto &unit : *this) {
		if (dynamic_cast<Object_Unit *>(unit.second)) {
			//auto bb = unit.second->GetBound();
			//if (bb.left < mCamera.x + WIDTH &&
			//	bb.right > mCamera.x &&
			//	bb.top < mCamera.y + HEIGHT &&
			//	bb.bottom > mCamera.y) {
			//}
			auto pos = unit.second->GetPosition();
			if (pos->x() > mCamera.x &&
				pos->x() < mCamera.x + WIDTH &&
				pos->y() > mCamera.y &&
				pos->y() < mCamera.y + HEIGHT) {
				unit.second->ObjectRender(delay);
			}
		}
		else {
			unit.second->ObjectRender(delay);
		}
	}
}

void Scene::OnKeyDown(int pKeyCode) {}
void Scene::OnKeyUp(int pKeyCode) {}

void Scene::Add(int pName, Object * pObject) {
	(*this)[pName] = pObject;
	pObject->mScene = this;
	pObject->AfterAddToScene();
}

void Scene::Remove(int pName) {
	for (map<int, Object *>::iterator it = this->begin(); it != this->end(); it++) {
		if ((it->first) == pName) {
			this->erase(it);
			break;
		}
	}
}