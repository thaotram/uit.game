#pragma once
#include <list>

#include "../Game/GameGlobal.h"
#include "../GameComponents/Node/Node.h"
using namespace std;

typedef void(*func)();

class Scene
{
protected:
	Scene() {
		mNode = new Node();
	};
	Node * mNode;
public:
	~Scene() {};

	void Update(float dt) {
		mNode->Update(dt);
	};
	void Draw() {
		mNode->Draw();
	};

	virtual void OnKeyDown(int keyCode) {};
	virtual void OnKeyUp(int keyCode) {};
	virtual void OnMouseDown(float x, float y) {};
};