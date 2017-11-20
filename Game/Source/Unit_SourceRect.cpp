#pragma once
#include "Unit_SourceRect.h"
#include "Unit.h"

void Unit_SourceRect::Update(Unit * pUnit, Unit_Entity * pEntity)
{
	(*this) = pUnit->GetJson()->GetFrame(
		pEntity->GetAnimation()
	);
}
void Unit_SourceRect::operator=(RECT pRect) {
	this->top = pRect.top;
	this->left = pRect.left;
	this->right = pRect.right;
	this->bottom = pRect.bottom;
}
