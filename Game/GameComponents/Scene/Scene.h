#pragma once
#include <d3dx9.h>
#include <d3d9.h>

#include "../Game/GameGlobal.h"

class Scene
{
protected: 
	Scene();

	// màu nền của Scene, khi Clear surface sẽ dùng màu của scene hiện tại để Clear.
	// Mình sẽ thay đổi tham số truyền vào ở class Game (file Game.cpp) ở đoạn clear của device.
	D3DCOLOR	mBackColor;
public:
	~Scene();

	// gọi trong lúc update của class game.
	// Tham số truyền vào là khoảng thời gian gọi giữa 2 frame được tính bằng giây.
	// Chính là cái biến delta trong vòng lặp của class Game, sử dụng cho việc tính vận tốc của vật, đếm thời gian 
	// (VD: như cứ 1s thì sinh quái vật lúc này sẽ dùng 1 biến khác cộng dồn biến dt này lại đến khi nào được 1s thì sẽ gọi hàm)
	virtual void Update(float dt);

	// khởi tạo các biến của scene
	virtual void LoadContent();

	// vẽ những Sprite sẽ được vẽ trong này bằng cách gọi hàm Draw của sprite trong này.
	// Hàm này sẽ được gọi sau mỗi lần update scene.
	virtual void Draw();

	// hàm được gọi khi có phím được nhấn xuống,
	// hàm này ngưng gọi khi k có phím nào được nhấn xuống tham số truyền vào là mã của Key đang được nhấn xuống
	virtual void OnKeyDown(int keyCode);

	// giống như hàm OnKeyDown nhưng được gọi khi có phím được nhả ra.
	virtual void OnKeyUp(int keyCode);

	// gọi khi có sự kiện chuột được nhấn xuống.
	virtual void OnMouseDown(float x, float y);

	// Lấy màu nền của Scene để sử dụng cho việc Clear màu.
	D3DCOLOR GetBackcolor();
};