#include "Scene_Manager.h"

Scene_Manager* Scene_Manager::mInstance = NULL;

Scene_Manager::Scene_Manager() {}
Scene_Manager::~Scene_Manager() {}

Scene_Manager * Scene_Manager::GetInstance()
{
	if (!mInstance) mInstance = new Scene_Manager();
	return mInstance;
}
Scene * Scene_Manager::GetCurrentScene()
{
	return mCurrentScene;
}

void Scene_Manager::Update(float dt)
{
	mCurrentScene->SceneRender(dt);
}
void Scene_Manager::ReplaceScene(Scene * scene)
{
	delete mCurrentScene;
	mCurrentScene = scene;
}
