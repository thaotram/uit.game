#include "Scene.h"
#include "../Object/Object.h"
#include "../Object_Unit/Object_Unit.h"

#define ef_ else if
#define margin 100
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

#define isRender	obj.second->mIsRender
#define isUpdate	obj.second->mIsUpdate
void Scene::SceneRender(float delay) {
	for (auto &obj : *this) {
		if (dynamic_cast<Object_Unit *>(obj.second)) {
			auto pos = obj.second->GetPosition();
			bool inCamera =
				pos->x() + margin > mCamera.x &&
				pos->x() - margin < mCamera.x + WIDTH &&
				pos->y() + margin > mCamera.y &&
				pos->y() - margin < mCamera.y + HEIGHT;
			if (inCamera) {
				isRender = true;
				isUpdate = true;
				obj.second->ObjectUpdateEvent(delay);
			}
			ef_(isUpdate) {		// !inCamera && isUpdate - Chỉ gọi một lần thôi
				obj.second->ObjectUpdateEvent(delay);
				isUpdate = false;
			}
			else {				// !inCamera && !isUpdate
				isRender = false;
			}
		}
		else {
			obj.second->ObjectUpdateEvent(delay);
		}
	}
	for (auto &obj : *this) {
		if (isRender == true) {
			obj.second->ObjectRender(delay);
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