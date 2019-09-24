#include "gs2d/scene/scene.hpp"

namespace gs {

Scene::Scene() {
  level_bundle = gs::LevelBundle(&l_proxy, &shared_holder, &camera);
  tex_holder = TextureHolder(&shared_holder);
}

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

void Scene::push_scene(Scene *next_scene) {
  SceneBuilder::build_scene(next_scene, app_window, app_state, dt, app_clock);
  std::shared_ptr<Scene> next_scene_ptr(next_scene);
  app_state->push_back(next_scene_ptr);
  next_scene_ptr->start();
}

void Scene::rollback_scene() {
  if (!app_state->empty())
    app_state->pop_back();
}

void Scene::set_app_window(sf::RenderWindow *app_window) {
  this->app_window = app_window;
}

void Scene::set_app_dt(float dt) { this->dt = dt; }

float Scene::get_delta_time() const { return dt; }

void Scene::set_app_clock(ClockHandler *app_clock) {
  this->app_clock = app_clock;
}

float Scene::get_frame_delta_time() const {
  return app_clock->get_elapsed_time().asSeconds();
}

void Scene::set_app_state(std::vector<std::shared_ptr<Scene>> *app_state) {
  this->app_state = app_state;
}

} // namespace gs
