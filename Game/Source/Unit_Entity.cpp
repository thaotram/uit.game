#include "Unit_Entity.h"
#include "Unit.h"

Unit_Entity::Unit_Entity() {
	mPosition = { 20,20 };
	mAnimation.SetState("_");
}

void Unit_Entity::Draw(Unit * pUnit) {
	pUnit->Draw(mTransform, mSourceRect, mPosition);
}

void Unit_Entity::Update(Unit * pUnit) {
	mAnimation.NextFrame(pUnit->GetJson());
	mSourceRect.Update(pUnit, this);
	mTransform.Update(pUnit, this);
}

Unit_SourceRect * Unit_Entity::GetSourceRect() {
	return &mSourceRect;
}

D3DXVECTOR2 * Unit_Entity::GetPosition() {
	return &mPosition;
}

Unit_Animation * Unit_Entity::GetAnimation() {
	return &mAnimation;
}

Unit_Transform * Unit_Entity::GetTransform() {
	return &mTransform;
}
