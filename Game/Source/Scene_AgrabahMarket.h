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
		this->AddChild("1 Map", "char", new Unit("Aladdin"));
		this->AddChild("2 Unit", "char", new Unit("Aladdin"));
		//this->AddChild("3 Map", "char", new Unit("Aladdin"));
	}
};

