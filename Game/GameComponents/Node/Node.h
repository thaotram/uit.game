#pragma once
#include <list>
#include <functional>
#include "../Sprite/Sprite.h"
using namespace std;

class Node
{
	typedef void (Node::*NodeFn)();
private:
	void eachNode(function<void(list<Node *>::iterator)> eachFunction);
protected:
	Sprite * mSprite;
	list<Node *> mChildren;
public:
	Node();
	~Node();

	void Update(float dt);
	void Draw();

	void SetSprite(Sprite * sprite);
	Sprite * GetSprite();
	void AddChild(Node * child);
	void RemoveChild(Node * child);
};
