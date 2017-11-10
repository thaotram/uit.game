#pragma once
#include <list>

#include "GameGlobal.h"
#include "nNode.h"
#include "nUnit.h"

using namespace std;

typedef void(*func)();

class Scene
{
protected:
	Scene() {
		mNode = new nNode();
	};
	nNode * mNode;
	nUnit * mUnit;
public:
	~Scene() {};

	void Update(float dt) {
		mUnit->Update(dt);
	};
	void Draw() {
		mUnit->Draw();
	};

	virtual void OnKeyDown(int keyCode) {};
	virtual void OnKeyUp(int keyCode) {};
	virtual void OnMouseDown(float x, float y) {};
};