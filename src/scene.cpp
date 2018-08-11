#include "gamesimple/abstract/scene.hpp"

Scene::Scene(SceneManager *scene_manager) {
        this->scene_manager = scene_manager;
}

Scene::Scene() {
}

Scene::~Scene() {
}

void Scene::reset_time_handlers(ClockHandler &clock_handler){
        for(std::vector<TimeHandler*>::iterator it = time_handlers.begin();
            it != time_handlers.end();
            ++it)
                clock_handler.restart_time_handler(*it);
}

void Scene::on_exit(){

}

void Scene::change_scene(Scene *next_scene) {
        scene_manager->change_scene(next_scene);
        delete this;
}

void Scene::set_scene_manager(SceneManager *scene_manager) {
        this->scene_manager = scene_manager;
}

SceneManager *Scene::get_scene_manager() {
        return scene_manager;
}
