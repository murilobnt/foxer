#include "gs2d_engine/scene/scene.hpp"

namespace gs {

Scene::Scene() {}

Scene::~Scene() {}

void Scene::reset_time_handlers(ClockHandler &clock_handler) {
  for (std::vector<TimeHandler *>::iterator it = time_handlers.begin();
       it != time_handlers.end(); ++it)
    clock_handler.restart_time_handler(*it);
}

void Scene::handle_event(sf::Event &event) {
  if (event.type == sf::Event::Closed) {
    app_window->close();
  }
}

void Scene::on_exit() {}

void Scene::change_scene(Scene *next_scene) {
  SceneBuilder::build_scene(next_scene, scene_proxy, app_window, app_clock);

  scene_proxy->change_scene(next_scene);
  delete this;
}

void Scene::set_scene_proxy(SceneProxy *scene_proxy) {
  this->scene_proxy = scene_proxy;
}

void Scene::set_app_window(sf::RenderWindow *app_window) {
  this->app_window = app_window;
}

void Scene::set_app_clock(ClockHandler *app_clock) {
  this->app_clock = app_clock;
}

float Scene::get_delta_time() const {
  return app_clock->get_elapsed_time().asSeconds();
}

} // namespace gs
