#include "Unit_Status.h"

Unit_Status::Unit_Status() : Unit("Status") {
	this->mEntities["number"] = new Unit_Entity({ 20,20 }, "number_s");

	number = this->mEntities["number"];
	number->GetAnimation()->SetCycleIndex(1);
}

bool Unit_Status::UpdateUnit()
{
	number->GetSourceRect()->Update(this, number);
	number->GetTransform()->Update(this, number);
	return true;
}
