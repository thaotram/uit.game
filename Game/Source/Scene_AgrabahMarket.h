#pragma once
#include <math.h>
#include <vector>
#include <d3dx9.h>
#include <d3d9.h>

#include "Scene.h"
#include "GameDebug.h"

#include "Unit_Aladdin.h";
#include "Unit_Camel.h";
#include "Unit_Peddler.h";
#include "Unit_Genie.h";
#include "Unit_Guards.h";
#include "Unit_Status.h";

using namespace std;

class AgrabahMarket : public Scene
{
public:
	AgrabahMarket();
	void AfterDrawUnit();
	void AfterUpdateUnit();
	void OnKeyDown(int pKeyCode);
};

