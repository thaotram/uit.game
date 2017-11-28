#pragma once
#include "Object_SourceRect.h"
#include "Object.h"

void Object_SourceRect::Update(Object * pObject) {
	(*this) = pObject->GetJson()->GetFrame(pObject);
}
void Object_SourceRect::operator=(RECT pRect) {
	this->top = pRect.top;
	this->left = pRect.left;
	this->right = pRect.right;
	this->bottom = pRect.bottom;
}