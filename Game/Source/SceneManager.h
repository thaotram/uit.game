#pragma once
#include "Scene.h"

class SceneManager
{
private:
	SceneManager();
	static SceneManager     *mInstance;
	Scene                   *mCurrentScene;
public:
	// lấy instance của SceneManager, thì instance này sẽ tồn tại từ đầu cho đến cuối game loop
	static SceneManager *GetInstance();
	~SceneManager();

	//hàm return Scene hiện tại
	Scene* GetCurrentScene();

	// Sẽ đc gọi liên tục với tần xuất phụ thuộc vào fps của game (fps 60 thì 1 giây gọi 60 lần)
	// trong hàm này sẽ gọi hàm update của Scene hiện tại và update nhựng thông tin ngoài scene nếu có
	void Update(float dt);

	// Thay thế scene hiện tại bằng 1 scene khác
	// trước khi thay thế sẽ xóa đi scene cũ để tránh tình trạng leak memory
	void ReplaceScene(Scene *scene);
};
