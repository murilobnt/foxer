#include "gs2d/app_cycle/scene_proxy.hpp"

#include "gs2d/scene/scene.hpp"

namespace gs {

SceneProxy::SceneProxy() {}

void SceneProxy::change_scene(Scene *next_scene) {
  scene->on_exit();
  scene = std::shared_ptr<Scene>(next_scene);
  scene->start();
}

void SceneProxy::start() { scene->start(); }

void SceneProxy::handle_event(sf::Event &event) { scene->handle_event(event); }

void SceneProxy::update() { scene->update(); }

void SceneProxy::draw_entities() { scene->draw_entities(); }

void SceneProxy::reset_time_handlers(ClockHandler &clock_handler) {
  scene->reset_time_handlers(clock_handler);
}

void SceneProxy::change_to_runtime_scene(Scene *next_scene) {
  last_scene = scene;
  scene = std::shared_ptr<Scene>(next_scene);
  scene->start();
}

void SceneProxy::set_last_scene() { scene = last_scene; }

Scene *SceneProxy::get_scene() const { return scene.get(); }

void SceneProxy::set_scene(Scene *scene) {
  this->scene = std::shared_ptr<Scene>(scene);
  this->scene->start();
}

} // namespace gs
