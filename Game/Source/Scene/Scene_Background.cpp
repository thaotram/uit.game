#include "Scene_Background.h"
#include "../Object/Object.h"

Scene_Background::Scene_Background() {
    clear();
}

Scene_Background::~Scene_Background(){
	if (this == NULL) return;
	for (auto &b : *this) {
		delete b;
	};
	clear();
}

void Scene_Background::operator<<(Object *pObject) { push_back(pObject); }

void Scene_Background::ObjectUpdateEvent(float delay) {
    if (this == NULL) return;
    for (auto &b : *this) {
        b->ObjectUpdateEvent(delay);
    };
}

void Scene_Background::ObjectRender(float delay) {
    if (this == NULL) return;
    for (auto &b : *this) {
        b->ObjectRender(delay);
    };
}