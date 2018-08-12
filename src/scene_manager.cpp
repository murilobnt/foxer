#include "gs2d_engine/concrete/scene_manager.hpp"

#include "gs2d_engine/abstract/scene.hpp"

SceneManager::SceneManager() {
}

SceneManager::~SceneManager() {
        delete scene;
}

void SceneManager::change_scene(Scene *next_scene) {
        scene->on_exit();
        scene = next_scene;
        scene->start();
}

void SceneManager::change_to_runtime_scene(Scene *next_scene) {
        last_scene = scene;
        scene = next_scene;
}

void SceneManager::remove_last_scene() {
        delete last_scene;
}

void SceneManager::start() {
        scene->start();
}

void SceneManager::handle_event(sf::Event event, sf::RenderWindow &screen) {
        scene->handle_event(event, screen);
}

void SceneManager::update() {
        scene->update();
}

void SceneManager::draw_entities(sf::RenderWindow &window) {
        scene->draw_entities(window);
}

void SceneManager::reset_time_handlers(ClockHandler &clock_handler) {
        scene->reset_time_handlers(clock_handler);
}

void SceneManager::set_last_scene() {
        scene = last_scene;
}

Scene *SceneManager::get_scene() const {
        return scene;
}

void SceneManager::set_scene(Scene *scene){
        this->scene = scene;
        this->scene->start();
}
