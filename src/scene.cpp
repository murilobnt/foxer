#include "gamesimple/abstract/scene.hpp"

Scene::Scene(SceneManager *sceneManager) { this->sceneManager = sceneManager; }

Scene::Scene() {}

Scene::~Scene() {}

void Scene::changeScene(Scene *nextScene) {
  this->sceneManager->changeScene(nextScene);
  delete this;
}

void Scene::setSceneManager(SceneManager *sceneManager) {
  this->sceneManager = sceneManager;
}

SceneManager *Scene::getSceneManager() { return this->sceneManager; }
