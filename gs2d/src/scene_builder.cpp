#include "gs2d/scene/scene.hpp"
#include "gs2d/scene/scene_builder.hpp"

namespace gs {

void SceneBuilder::build_scene(Scene *scene, SceneProxy *scene_proxy,
                               sf::RenderWindow *app_window, float dt) {
  scene->set_scene_proxy(scene_proxy);
  scene->set_app_window(app_window);
  scene->set_app_dt(dt);
}

} // namespace gs
