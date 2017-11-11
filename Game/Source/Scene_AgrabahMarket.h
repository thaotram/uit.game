#pragma once
#include <math.h>
#include <vector>
#include <d3dx9.h>
#include <d3d9.h>

#include "Scene.h"
#include "GameDebug.h"

using namespace std;

class AgrabahMarket : public Scene
{
public:
	AgrabahMarket() {
		//this->AddChild("1", "1", new Unit("Aladdin"));
		//(*this)["1"]["1"]->SetPosition(211, 250);

		this->AddChild("2", "1", new Unit("Aladdin"));
		(*this)["2"]["1"]->log = true;
		(*this)["2"]["1"]->SetPosition(200, 200);
	}
	void AfterDrawUnit() {
		//GameDebug::Draw(RECT{ 248,300,500,500 });
		GameDebug::DrawHL(200, 1);
		GameDebug::DrawVL(200, 1);
	}
};

