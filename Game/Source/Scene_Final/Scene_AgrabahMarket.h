#pragma once
#include <math.h>
#include <vector>
#include <d3dx9.h>
#include <d3d9.h>

#include "../Scene/Scene.h"
#include "../GameDebug.h"

using namespace std;

class Scene_AgrabahMarket final : public Scene
{
private:
	void AddBlock(string str);
public:
	Scene_AgrabahMarket();

};

