#pragma once
#include <math.h>
#include <vector>
#include <d3dx9.h>
#include <d3d9.h>

#include "Scene.h"
#include "Aladdin.h"

using namespace std;

class AgrabahMarket : public Scene
{
public:
	AgrabahMarket() {
		//mNode->SetSprite(new Aladdin());
		//mNode->GetSprite()->SetScale(3, 3);
		//mNode->GetSprite()->SetPosition(3, 3);
		mUnit = new nUnit("Aladdin");
	}
};

