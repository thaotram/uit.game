#include "Scene_Background.h"
#include "../Object/Object.h"
#define forList(method) if (this != NULL) for (auto &b : *this) b->method(delay);
Scene_Background::Scene_Background() {
	clear();
}

Scene_Background::~Scene_Background() {
	if (this != NULL) for (auto &b : *this) delete b;
	clear();
}

void Scene_Background::operator<<(Object *pObject) { 
	//# Chèn phần tử vào
	push_back(pObject); 
}

void Scene_Background::ObjectUpdateEvent(float delay) {
	forList(ObjectUpdateEvent);
}

void Scene_Background::ObjectRender(float delay) {
	forList(ObjectRender);
}