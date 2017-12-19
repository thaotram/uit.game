#pragma once
#include <math.h>
#include <vector>
#include <d3dx9.h>
#include <d3d9.h>

#include "../Scene/Scene.h"
#include "../Scene/Scene_ObjectStore.h"
#include "../GameDebug.h"

#include "../Object_Map_Final/Object_Map_AgrabahMarket_Back.h"
#include "../Object_Map_Final/Object_Map_AgrabahMarket_Front.h"

#include "../Object_Unit_Final/Object_Unit_Apple.h"
#include "../Object_Unit_Final/Object_Unit_Aladdin.h"

#include "../Object_Unit_Final/Object_Unit_Static_Abubonus.h"
#include "../Object_Unit_Final/Object_Unit_Static_Apple.h"
#include "../Object_Unit_Final/Object_Unit_Static_Black_Magic_Lamp.h"
#include "../Object_Unit_Final/Object_Unit_Static_Block_Drop.h"
#include "../Object_Unit_Final/Object_Unit_Static_Extra_Health.h"
#include "../Object_Unit_Final/Object_Unit_Static_Genie_Bonus.h"
#include "../Object_Unit_Final/Object_Unit_Static_Restart_Point.h"
#include "../Object_Unit_Final/Object_Unit_Static_Spend_These.h"

#include "../../Define.h"

using namespace std;

class Scene_AgrabahMarket final : public Scene {
public:
	Scene_AgrabahMarket();
	~Scene_AgrabahMarket() {};
};
