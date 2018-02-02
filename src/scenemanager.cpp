#include "reusable/concrete/scenemanager.hpp"

#include "reusable/abstract/scene.hpp"

SceneManager::SceneManager() {
  // this->scene = new MenuScene(textureManager, this);
  //this->textureManager = textureManager;
}

SceneManager::~SceneManager() { delete scene; }

void SceneManager::changeScene(SceneCatalog sceneCatalog) {
  scene->onExit();
  delete scene;
  switch (sceneCatalog) {
  case GAME:
    // this->scene = new GameScene(textureManager, this);
    // this->scene->start();
    break;
  case MENU:
    // this->scene = new MenuScene(textureManager, this);
    // this->scene->start();
    break;
  }
}

void SceneManager::changeToRuntimeScene(SceneCatalog sceneCatalog) {
  this->lastScene = this->scene;

  switch (sceneCatalog) {
  case GAMEMENU:
    // this->scene = new GameMenuScene(textureManager, this);
    // this->scene->start();
    break;
  }
}

void SceneManager::removeLastScene() { delete lastScene; }

void SceneManager::start() { scene->start(); }

void SceneManager::handleEvent(sf::Event event, sf::RenderWindow &screen) {
  scene->handleEvent(event, screen);
}

void SceneManager::update() { scene->update(); }

void SceneManager::drawEntities(sf::RenderWindow &window) {
  scene->drawEntities(window);
}

void SceneManager::doInternalTimedActions() { scene->doInternalTimedActions(); }

void SceneManager::resetTimeHandlers(ClockHandler &clockHandler) {
  scene->resetTimeHandlers(clockHandler);
}

void SceneManager::setLastScene() {
  this->scene = lastScene;
  this->scene->resumeScene();
}

Scene *SceneManager::getScene() const { return this->scene; }

void SceneManager::setScene(Scene *scene) {
  this->scene = scene;
  scene->start();
}
