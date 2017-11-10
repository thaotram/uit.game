#pragma once
#include <math.h>
#include <vector>
#include <d3dx9.h>
#include <d3d9.h>

#include "Scene.h"

using namespace std;

class AgrabahMarket : public Scene
{
public:
	AgrabahMarket() {
		this->AddChild("1", "char", new Unit("Aladdin"));
	}
};

