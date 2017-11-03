#pragma once
#include <list>
#include <functional>
#include "../Sprite/Sprite.h"
using namespace std;

class Node
{
	typedef void (Node::*NodeFn)();
private:
	void eachNode(function<void(list<Node *>::iterator)> eachFunction)
	{
		for (
			list<Node *>::iterator it = mChildren.begin();
			it != mChildren.end();
			++it
			)
		{
			eachFunction(it);
		}
	}
protected:
	Sprite * mSelf;
	list<Node *> mChildren;
public:
	Node() {
		mSelf = nullptr;
	}
	~Node() {
		delete mSelf;
		eachNode([=](list<Node *>::iterator it) {
			delete *it;
		});
	}

	void Update(float dt) {
		eachNode([=](list<Node *>::iterator it) {
			(**it).Update(dt);
		});
	};
	void Draw() {
		eachNode([=](list<Node *>::iterator it) {
			(**it).Draw();
		});
	};

	void AddChild(Node * child) {
		mChildren.push_back(child);
	}
};

