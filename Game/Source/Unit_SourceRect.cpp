#pragma once
#include "Unit_SourceRect.h"
#include "Unit.h"

Unit * UNIT_SOURCERECT::operator<<(Unit * pUnit)
{
	(*this) = pUnit->GetJson()->GetFrame(
		pUnit->GetAnimation()
	);
	return pUnit;
}
void UNIT_SOURCERECT::operator=(RECT pRect) {
	this->top = pRect.top;
	this->left = pRect.left;
	this->right = pRect.right;
	this->bottom = pRect.bottom;
}
