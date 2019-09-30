#include "foxer/other/geared_up/rpg_level.hpp"

namespace fox {

void RPGLevel::add_exit_area(std::unique_ptr<ExitArea> area) {
  exit_areas.push_back(std::move(area));
}

RPGLevel::RPGLevel() {}
RPGLevel::RPGLevel(const std::string &json) : SampleLevel(json) {}
RPGLevel::RPGLevel(const std::string &json,
                   const std::string &start_position_id)
    : SampleLevel(json, start_position_id) {}

void RPGLevel::on_fade_out() { change_level(loader->get_level()); }
void RPGLevel::on_fade_in() {}

void RPGLevel::handle_level_events(const float &delta_time) {
  for (const std::unique_ptr<ExitArea> &area : exit_areas)
    area->verify_collision_with(player, delta_time);
}

void RPGLevel::control_camera(const float &delta_time) {
  camera->move(
      sf::Vector2f((player->get_sprite_position() - camera->get_center())) *
      (delta_time * 5));
  adjust_camera();
}

void RPGLevel::stop_player(const float &delta_time) {
  player->set_movement(sf::Vector2f(0, 0));
  player->animate();
  *delay = sf::Vector2f((player->get_sprite_position() - camera->get_center()) *
                        (delta_time * 5));
}

void RPGLevel::initialise_camera() {
  camera->center_at_position(player->get_sprite_position() -
                             (*delay) * (fading_speed / 5.f));
}

void RPGLevel::adjust_camera() {
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

void RPGLevel::_change_level(std::shared_ptr<RPGLevel> level) {
  level->set_delay(delay);
  level->set_player(player);
  change_level(level);
}

void RPGLevel::set_delay(sf::Vector2f *delay) { this->delay = delay; }

std::shared_ptr<RPGLevel>
RPGLevel::build_level(std::shared_ptr<RPGLevel> level) {
  level->set_delay(delay);
  level->set_player(player);
  level->set_level_bundle(bundle);
  return level;
}

} // namespace fox
