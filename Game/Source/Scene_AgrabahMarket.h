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
		this->AddChild("2", "1", new Unit("Aladdin"));
		(*this)["2"]["1"]->SetPosition(300, 300);
		(*this)["2"]["1"]->GetAnimation()->SetState("stand_cut");
		(*this)["2"]["1"]->log = true;

		this->AddChild("2", "2", new Unit("Aladdin"));
		(*this)["2"]["2"]->SetPosition(600, 300);
		(*this)["2"]["2"]->GetAnimation()->SetState("stand_cut");
		(*this)["2"]["2"]->GetTransform()->SetFlip(true, false);
	}
	void AfterDrawUnit() {
		GameDebug::DrawHL(300, 1);
		GameDebug::DrawVL(300, 1);
		GameDebug::DrawVL(600, 1);
	}
};

