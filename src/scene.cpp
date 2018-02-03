#include "gamesimple/abstract/scene.hpp"

Scene::Scene(SceneManager *sceneManager) { this->sceneManager = sceneManager; }

Scene::Scene(SceneManager *sceneManager, TextureLoader &textureLoader) {
  this->sceneManager = sceneManager;
  this->textureLoader = textureLoader;
}

Scene::Scene(SceneManager *sceneManager, std::string pathToImage, int w, int h,
      bool isRepeated, bool hasBitmask) {
  this->sceneManager = sceneManager;
  createTextureLoader(pathToImage, w, h, isRepeated, hasBitmask);
}

void Scene::changeScene(Scene *nextScene) {
  this->sceneManager->changeScene(nextScene);
}

void Scene::setTextureLoader(TextureLoader &textureLoader) {
  this->textureLoader = textureLoader;
}

void Scene::createTextureLoader(std::string pathToImage, int w, int h,
                                bool isRepeated, bool hasBitmask) {
  this->textureLoader =
      TextureLoader(pathToImage, w, h, isRepeated, hasBitmask);
}

void Scene::setSceneManager(SceneManager *sceneManager) {
  this->sceneManager = sceneManager;
}

SceneManager *Scene::getSceneManager() { return this->sceneManager; }
