#include "gs2d_engine/abstract/scene.hpp"

namespace gs {

Scene::~Scene() {
}

void Scene::reset_time_handlers(ClockHandler &clock_handler){
        for(std::vector<TimeHandler*>::iterator it = time_handlers.begin();
            it != time_handlers.end();
            ++it)
                clock_handler.restart_time_handler(*it);
}

void Scene::handle_event(sf::Event &event){
    if (event.type == sf::Event::Closed) {
            app_window->close();
    }
}

void Scene::on_exit(){

}

void Scene::change_scene(Scene *next_scene) {
        next_scene->set_scene_manager(scene_manager);
        next_scene->set_app_window(app_window);
        scene_manager->change_scene(next_scene);
        delete this;
}

void Scene::set_scene_manager(SceneManager *scene_manager) {
        this->scene_manager = scene_manager;
}

void Scene::set_app_window(sf::RenderWindow *app_window){
    this->app_window = app_window;
}

}
