#include "reusable/abstract/scene.hpp"

Scene::Scene(SceneManager* sceneManager){
	this->sceneManager = sceneManager;
}

void Scene::setSceneManager(SceneManager* sceneManager){
	this->sceneManager = sceneManager;
}

SceneManager* Scene::getSceneManager(){
	return this->sceneManager;
}

void Scene::changeScene(SceneCatalog sceneCatalog){
	this->sceneManager->changeScene(sceneCatalog);
}
