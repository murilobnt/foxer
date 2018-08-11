#include "gamesimple/abstract/scene.hpp"

Scene::Scene(SceneManager *sceneManager) {
        this->sceneManager = sceneManager;
}

Scene::Scene() {
}

Scene::~Scene() {
}

void Scene::resetTimeHandlers(ClockHandler &clockHandler){
        for(std::vector<TimeHandler*>::iterator it = timeHandlers.begin();
            it != timeHandlers.end();
            ++it)
                clockHandler.restartTimeHandler(*it);
}

void Scene::onExit(){

}

void Scene::changeScene(Scene *nextScene) {
        sceneManager->changeScene(nextScene);
        delete this;
}

void Scene::setSceneManager(SceneManager *sceneManager) {
        this->sceneManager = sceneManager;
}

SceneManager *Scene::getSceneManager() {
        return sceneManager;
}
