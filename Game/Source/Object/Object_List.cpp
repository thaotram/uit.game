#include "Object_List.h"
#include "../Object/Object.h"
#define forList(method) if (this != NULL) for (auto &b : *this) b->method(delay);
Object_List::Object_List() {
	clear();
}

Object_List::~Object_List() {
	if (this != NULL) for (auto &b : *this) delete b;
	clear();
}

void Object_List::operator<<(Object *pObject) { 
	//# Chèn phần tử vào
	push_back(pObject); 
}

void Object_List::ObjectUpdateEvent(float delay) {
	forList(ObjectUpdateEvent);
}

void Object_List::ObjectRender(float delay) {
	forList(ObjectRender);
}