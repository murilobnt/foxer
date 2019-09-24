#include "sample_level.hpp"

SampleLevel::SampleLevel() {}

SampleLevel::SampleLevel(gs::LevelBundle *bundle, SampleBundle *s_bundle,
                         const std::string &json_path,
                         const std::string &start_position_id, bool load,
                         bool fade_in)
    : gs::SampleLevel(bundle, s_bundle->character, json_path, start_position_id,
                      load, fade_in),
      CommonLevel(s_bundle->delay), s_bundle(s_bundle) {}

SampleLevel::SampleLevel(gs::LevelBundle *bundle, SampleBundle *s_bundle,
                         const std::string &json_path, bool load, bool fade_in)
    : gs::SampleLevel(bundle, s_bundle->character, json_path, load, fade_in),
      CommonLevel(s_bundle->delay), s_bundle(s_bundle) {}

void SampleLevel::add_exit_area(std::unique_ptr<SampleExitArea> area) {
  exit_areas.push_back(std::move(area));
}

void SampleLevel::on_fade_out() { change_level(loader->get_level()); }

void SampleLevel::on_fade_in() {}

void SampleLevel::handle_level_events(const float &delta_time) {
  for (const std::unique_ptr<gs::ExitArea> &area : exit_areas)
    area->verify_collision_with(character, delta_time);
}

void SampleLevel::control_camera(const float &delta_time) {
  camera->move(
      sf::Vector2f((character->get_sprite_position() - camera->get_center())) *
      (delta_time * 5));
  adjust_camera();
}

void SampleLevel::adjust_camera() {}
