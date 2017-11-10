#pragma once
#include <list>
#include <functional>
#include "Sprite.h"
using namespace std;

class nNode
{
private:
	void eachNode(function<void(list<nNode *>::iterator)> eachFunction)
	{
		for (
			list<nNode *>::iterator it = mChildren.begin();
			it != mChildren.end();
			++it
			)
		{
			eachFunction(it);
		}
	}
protected:
	Sprite * mSprite;
	list<nNode *> mChildren;
public:
	nNode()
	{
		mSprite = nullptr;
	}
	~nNode()
	{
		delete mSprite;
		eachNode([=](list<nNode *>::iterator it) {
			delete *it;
		});
	}

	void Update(float dt) {
		if (mSprite != nullptr) mSprite->Update(dt);
		eachNode([=](list<nNode *>::iterator it) {
			(**it).Update(dt);
		});
	}
	void Draw() {
		if (mSprite != nullptr) mSprite->Draw();
		eachNode([=](list<nNode *>::iterator it) {
			(**it).Draw();
		});
	}

	void SetSprite(Sprite * sprite) {
		if (mSprite != nullptr) delete mSprite;
		mSprite = sprite;
	}
	Sprite * GetSprite() {
		return mSprite;
	}
	void AddChild(nNode * child) {
		mChildren.push_back(child);
	}
	void RemoveChild(nNode * child) {
		mChildren.remove(child);
		delete child;
	}
};
