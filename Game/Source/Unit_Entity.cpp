#include "Unit_Entity.h"
#include "Unit.h"

//! Unit_Entity
void Unit_Entity::Draw(Unit * pUnit) {
	pUnit->Draw(mTransform, mSourceRect, mPosition);
}
void Unit_Entity::Update(Unit * pUnit) {
	mAnimation.NextFrame(pUnit, this);
	mSourceRect.Update(pUnit, this);
	mTransform.Update(pUnit, this);
}

Unit_SourceRect * Unit_Entity::GetSourceRect() {
	return &mSourceRect;
}
Unit_Vector2 * Unit_Entity::GetPosition() {
	return &mPosition;
}
Unit_Animation * Unit_Entity::GetAnimation() {
	return &mAnimation;
}
Unit_Transform * Unit_Entity::GetTransform() {
	return &mTransform;
}

//! Unit_Entities
void Unit_Entities::EachEntity(function<void(Unit_Entity*)> pEachEntity) {
	for (auto &unit : *this) {
		pEachEntity(unit.second);
	}
}

void Unit_Entities::Draw(Unit * pUnit) {
	EachEntity([=](Unit_Entity * pEntity) {
		pEntity->Draw(pUnit);
	});
}

void Unit_Entities::Update(Unit * pUnit) {
	EachEntity([=](Unit_Entity * pEntity) {
		pEntity->Update(pUnit);
	});
}
