#pragma once
#include <math.h>
#include <vector>
#include <d3dx9.h>
#include <d3d9.h>

#include "../GameComponents/Scene/Scene.h"
#include "../GameComponents/Node/Unit.h"

using namespace std;

class DemoScene : public Scene
{
public:
	DemoScene() {
		mNode->SetSprite(new Unit("Aladdin", 0xffff00ff));
		mNode->GetSprite()->SetScale(4, 4);
		mNode->GetSprite()->SetPosition(100,100);
	}
};

