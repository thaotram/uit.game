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
Scene::Scene() {
	mBlood = 7;
	mApple = 0;
	mSpendthese = 0;
	mExtrahealth = 0;
	mScore = 0;
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
			else if (isUpdate) {		// !inCamera && isUpdate - Chỉ gọi một lần thôi
				obj->ObjectUpdateEvent(delay);
				isUpdate = false;
			}
			else {						// !inCamera && !isUpdate
				isRender = false;
			}
		}
		else {
			obj->ObjectUpdateEvent(delay);
		}
	}
	
	for (auto &obj : mRemoveList) {
		this->remove(&*obj);
		delete &*obj;
	}
	mRemoveList.clear();

	for (auto &obj : *this) {
		if (isRender == true) {
			obj->ObjectRender(delay);
		}
	}
	// GameDebug::Title("Apple:" + to_string(mApple) + ",Spend these:" + to_string(mSpendthese));
}

void Scene::OnKeyDown(int pKeyCode) {}
void Scene::OnKeyUp(int pKeyCode) {}

list<Object *>::iterator Scene::Add(list<Object *>::iterator pIt, Object * pObject) {
	pObject->mScene = this;
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