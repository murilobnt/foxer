#include "common_level.hpp"

CommonLevel::CommonLevel() {}

CommonLevel::CommonLevel(sf::Vector2f *delay) : delay(delay) {}

void CommonLevel::stop_character(gs::MainObject *character, gs::Camera *camera,
                                 const float &delta_time) {
  character->set_movement(sf::Vector2f(0, 0));
  character->animate();
  *delay =
      sf::Vector2f((character->get_sprite_position() - camera->get_center()) *
                   (delta_time * 5));
}

void CommonLevel::initialise_camera(gs::MainObject *character,
                                    gs::Camera *camera,
                                    const int &fading_speed) {
  camera->center_at_position(character->get_sprite_position() -
                             (*delay) * (fading_speed / 5.f));
}

void CommonLevel::adjust_camera(gs::Camera *camera,
                                const sf::Vector2u level_size,
                                const sf::Vector2u tile_size) {
  sf::Vector2f camera_size = camera->get_size();
  sf::Vector2f center = camera->get_center();
  sf::Vector2f final_position = center;

  if (center.x - (camera_size.x / 2) < 0)
    final_position.x = camera_size.x / 2;
  if (center.y - (camera_size.y / 2) < 0)
    final_position.y = camera_size.y / 2;
  if (center.x + (camera_size.x / 2) > level_size.x * tile_size.x)
    final_position.x = (level_size.x * tile_size.x) - (camera_size.x / 2);
  if (center.y + (camera_size.y / 2) > level_size.y * tile_size.y)
    final_position.y = (level_size.y * tile_size.y) - (camera_size.y / 2);

  camera->center_at_position(final_position);
}
