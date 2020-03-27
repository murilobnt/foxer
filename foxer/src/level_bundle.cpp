#include "foxer/game/level/level_bundle.hpp"

namespace fox {

LevelBundle::LevelBundle() {}

LevelBundle::LevelBundle(MainObject *player_ref,
                         const sf::Vector2f &cam_viewport_size) {
  this->player_ref = player_ref;
  this->camera = Camera(cam_viewport_size);
}

} // namespace fox
