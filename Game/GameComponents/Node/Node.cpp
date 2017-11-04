#include "Node.h"

Node::Node()
{
	mSprite = nullptr;
}
Node::~Node()
{
	delete mSprite;
	eachNode([=](list<Node *>::iterator it) {
		delete *it;
	});
}

void Node::eachNode(function<void(list<Node*>::iterator)> eachFunction)
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

void Node::Update(float dt) {
	if (mSprite != nullptr) mSprite->Update(dt);
	eachNode([=](list<Node *>::iterator it) {
		(**it).Update(dt);
	});
}
void Node::Draw() {
	if (mSprite != nullptr) mSprite->Draw();
	eachNode([=](list<Node *>::iterator it) {
		(**it).Draw();
	});
}

void Node::SetSprite(Sprite * sprite) {
	if (mSprite != nullptr) delete mSprite;
	mSprite = sprite;
}
Sprite * Node::GetSprite() {
	return mSprite;
}

void Node::AddChild(Node * child) {
	mChildren.push_back(child);
}
void Node::RemoveChild(Node * child) {
	mChildren.remove(child);
	delete child;
}
