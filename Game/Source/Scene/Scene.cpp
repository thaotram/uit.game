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
		delete unit;
	}
}

#define isRender	obj->mIsRender
#define isUpdate	obj->mIsUpdate
void Scene::SceneRender(float delay) {
	for (auto &obj : *this) {
		if (dynamic_cast<Object_Unit *>(obj)) {
			auto pos = obj->GetPosition();
			bool inCamera =
				pos->x() + margin > mCamera.x &&
				pos->x() - margin < mCamera.x + WIDTH &&
				pos->y() + margin > mCamera.y &&
				pos->y() - margin < mCamera.y + HEIGHT;
			if (inCamera) {
				isRender = true;
				isUpdate = true;
				obj->ObjectUpdateEvent(delay);
			}
			ef_(isUpdate) {		// !inCamera && isUpdate - Chỉ gọi một lần thôi
				obj->ObjectUpdateEvent(delay);
				isUpdate = false;
			}
			else {				// !inCamera && !isUpdate
				isRender = false;
			}
		}
		else {
			obj->ObjectUpdateEvent(delay);
		}
	}
	for (auto &obj : *this) {
		if (isRender == true) {
			obj->ObjectRender(delay);
		}
	}
}

void Scene::OnKeyDown(int pKeyCode) {}
void Scene::OnKeyUp(int pKeyCode) {}

void Scene::Add(list<Object *>::iterator pIt, Object * pObject) {
	(*this).insert(pIt, pObject);
	pObject->mScene = this;
	pObject->AfterAddToScene();
}

void Scene::Add(Object * pObject) {
	Add(this->end(), pObject);
}

void Scene::Remove(Object * pObject){
	this->remove(pObject);
}