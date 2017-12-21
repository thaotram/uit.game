#include "Scene_Status.h"
#include "../Object_Status_Final/Object_Status_Apple.h"
#include "../Object_Status_Final/Object_Status_Health_Meter.h"
#include "../Object_Status_Final/Object_Status_Life.h"
#include "../Object_Status_Final/Object_Status_Magic_Lamp.h"
#include "../Object_Status_Final/Object_Status_Number_L.h"
#include "../Object_Status_Final/Object_Status_Number_S.h"
#include "../Object_Status_Final/Object_Status_Spendthese.h"

void Scene_Status::operator<<(Object * pObject) {
	push_back(pObject);
}

Scene_Status::Scene_Status() {
	(*this) << new Object_Status_Apple();
	(*this) << new Object_Status_Number_S(296, 200, S_Apple_Ones);
	(*this) << new Object_Status_Number_S(288, 200, S_Apple_Tens);

	(*this) << new Object_Status_Spendthese();
	(*this) << new Object_Status_Number_S(253, 200, S_Spendthese);

	(*this) << new Object_Status_Life();
	(*this) << new Object_Status_Number_S(42, 200, S_Life);

	(*this) << new Object_Status_Magic_Lamp();
	(*this) << new Object_Status_Health_Meter();

	(*this) << new Object_Status_Number_L(275, 20, L_Score_Ones);
	(*this) << new Object_Status_Number_L(258, 20, L_Score_Tens);
	(*this) << new Object_Status_Number_L(241, 20, L_Score_Hundreds);
	(*this) << new Object_Status_Number_L(224, 20, L_Score_Thousand);
}

void Scene_Status::ObjectUpdateEvent(float delay) {
	  for (auto &b : *this) {
		  b->ObjectUpdateEvent(delay);
	  };
}

void Scene_Status::ObjectRender(float delay) {
	  for (auto &b : *this) {
		  b->ObjectRender(delay);
	  };
}