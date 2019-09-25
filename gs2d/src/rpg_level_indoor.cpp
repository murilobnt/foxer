#include "gs2d/other/geared_up/rpg_level_indoor.hpp"

namespace gs {

RPGLevelIndoor::RPGLevelIndoor() {}
RPGLevelIndoor::RPGLevelIndoor(const std::string &json) : RPGLevel(json) {}
RPGLevelIndoor::RPGLevelIndoor(const std::string &json,
                               const std::string &start_position_id)
    : RPGLevel(json, start_position_id) {}

void RPGLevelIndoor::control_camera(const float &delta_time) {
  camera->move(
      sf::Vector2f((player->get_sprite_position() - camera->get_center())) *
      (delta_time * 5));
}

} // namespace gs
