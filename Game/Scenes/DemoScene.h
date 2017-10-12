#pragma once
#include <math.h>
#include <vector>
#include <d3dx9.h>
#include <d3d9.h>

#include "../GameComponents/Scene/Scene.h"

using namespace std;
//#include "../GameComponents/Sprite.h"
//#include "../GameComponents/Animation.h"

class DemoScene : public Scene
{
public:
	DemoScene();

	void Update(float dt);
	void LoadContent();
	void Draw();

protected:
	//Animation *mGoldBlock;
	float mTimeCounter;
};

