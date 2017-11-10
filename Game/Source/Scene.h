#pragma once
#include <list>

#include "GameGlobal.h"
#include "Node.h"
#include "nUnit.h"

using namespace std;

typedef void(*func)();

class Scene
{
protected:
	Scene() {
		mNode = new Node();
	};
	Node * mNode;
	nUnit * mUnit;
public:
	~Scene() {};

	void Update(float dt) {
		mNode->Update(dt);
		mUnit->Update(dt);
	};
	void Draw() {
		mNode->Draw();
		mUnit->Draw();
	};

	virtual void OnKeyDown(int keyCode) {};
	virtual void OnKeyUp(int keyCode) {};
	virtual void OnMouseDown(float x, float y) {};
};