#include "gamesimple/abstract/scene.hpp"

Scene::Scene(SceneManager *sceneManager) { this->sceneManager = sceneManager; }

void Scene::changeScene(Scene *nextScene) {
  this->sceneManager->changeScene(nextScene);
}

void Scene::setSceneManager(SceneManager *sceneManager) {
  this->sceneManager = sceneManager;
}

SceneManager *Scene::getSceneManager() { return this->sceneManager; }
