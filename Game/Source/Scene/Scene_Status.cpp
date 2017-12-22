#include "Scene_Status.h"
#include "../Object/Object.h"
#include "../Object_Status_Final/Object_Status_Apple.h"
#include "../Object_Status_Final/Object_Status_Health_Meter.h"
#include "../Object_Status_Final/Object_Status_Life.h"
#include "../Object_Status_Final/Object_Status_Magic_Lamp.h"
#include "../Object_Status_Final/Object_Status_Number_L.h"
#include "../Object_Status_Final/Object_Status_Number_S.h"
#include "../Object_Status_Final/Object_Status_Spendthese.h"

void Scene_Status::operator<<(Object *pObject) { push_back(pObject); }

Scene_Status::Scene_Status() {
    clear();
    (*this) << new Object_Status_Apple();
    (*this) << new Object_Status_Number_S(S_Apple_Ones);
    (*this) << new Object_Status_Number_S(S_Apple_Tens);

    (*this) << new Object_Status_Spendthese();
    (*this) << new Object_Status_Number_S(S_Spendthese);

    (*this) << new Object_Status_Life();
    (*this) << new Object_Status_Number_S(S_Life);

    (*this) << new Object_Status_Magic_Lamp();
    (*this) << new Object_Status_Health_Meter();

    (*this) << new Object_Status_Number_L(L_Score_Ones);
    (*this) << new Object_Status_Number_L(L_Score_Tens);
    (*this) << new Object_Status_Number_L(L_Score_Hundreds);
    (*this) << new Object_Status_Number_L(L_Score_Thousand);
}

void Scene_Status::ObjectUpdateEvent(float delay) {
    if (this == NULL) return;
    for (auto &b : *this) {
        b->ObjectUpdateEvent(delay);
    };
}

void Scene_Status::ObjectRender(float delay) {
    if (this == NULL) return;
    for (auto &b : *this) {
        b->ObjectRender(delay);
    };
}