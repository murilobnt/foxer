#include "foxer/scene/scene.hpp"
#include "foxer/scene/scene_builder.hpp"

namespace fox {

void SceneBuilder::build_scene(Scene *scene, sf::RenderWindow *app_window,
                               std::vector<std::shared_ptr<Scene>> *app_state,
                               float dt, ClockHandler *app_clock) {
  scene->set_app_window(app_window);
  scene->set_app_dt(dt);
  scene->set_app_clock(app_clock);
  scene->set_app_state(app_state);
}

} // namespace fox
