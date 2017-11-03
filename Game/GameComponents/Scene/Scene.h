#pragma once
#include <d3dx9.h>
#include <d3d9.h>
#include <list>

#include "../Game/GameGlobal.h"
#include "../GameComponents/Sprite/Sprite.h"

#include "../GameComponents/Node/Node.h"
using namespace std;

typedef void(*func)();

class Scene
{
protected:
	Scene() {
		mNode = new Node();
		LoadContent();
	};
	Node * mNode;
public:
	~Scene() {};

	// gọi trong lúc update của class game.
	// Tham số truyền vào là khoảng thời gian gọi giữa 2 frame được tính bằng giây.
	// Chính là cái biến delta trong vòng lặp của class Game, sử dụng cho việc tính vận tốc của vật, đếm thời gian 
	// (VD: như cứ 1s thì sinh quái vật lúc này sẽ dùng 1 biến khác cộng dồn biến dt này lại đến khi nào được 1s thì sẽ gọi hàm)
	virtual void Update(float dt) {
		//mNode->Update(dt);
	};

	// vẽ những Sprite sẽ được vẽ trong này bằng cách gọi hàm Draw của sprite trong này.
	// Hàm này sẽ được gọi sau mỗi lần update scene.
	virtual void Draw() {
		//mNode->Draw();
		//x.Draw();
	};

	// khởi tạo các biến của scene
	virtual void LoadContent() {};

	virtual void OnKeyDown(int keyCode) {};
	virtual void OnKeyUp(int keyCode) {};
	virtual void OnMouseDown(float x, float y) {};
};