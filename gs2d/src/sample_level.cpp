#include "gs2d/other/geared_up/sample_level.hpp"

namespace gs {

SampleLevel::SampleLevel() {}

SampleLevel::SampleLevel(LevelBundle *bundle, MainObject *character,
                         const std::string &json_level, bool load, bool fade_in)
    : TiledLevel(bundle, json_level, load) {
  this->character = character;
  this->fade_in = fade_in;
  fading_speed = 15;
}

SampleLevel::SampleLevel(LevelBundle *bundle, MainObject *character,
                         const std::string &json_level,
                         const std::string &start_position_id, bool load,
                         bool fade_in)
    : TiledLevel(bundle, json_level, load) {
  this->character = character;
  this->fade_in = fade_in;
  fading_speed = 15;
  this->start_position_id = start_position_id;
}

void SampleLevel::init() {
  TiledJsonObj start_pos = get_event(start_position_id);
  character->set_sprite_position(start_pos.x, start_pos.y);
  fader = Fader(
      sf::Vector2f(level_size.x * tile_size.x, level_size.y * tile_size.y));

  if (fade_in)
    fader.start_fade_in();

  level_init();
}

void SampleLevel::handle_game_events(const float &delta_time) {
  character->control_entity(delta_time);
  collision_map.verify_collision(*character);
  character->time_trigger();
  character->move();

  handle_level_events(delta_time);
}

void SampleLevel::handle_fade(const FadeState &fade_state) {
  character->time_trigger();
  switch (fade_state) {
  case FADING_OUT:
    if (fader.fade_out(fading_speed))
      on_fade_out();
    break;
  case FADING_IN:
    if (fader.fade_in(fading_speed))
      on_fade_in();
    break;
  }
}

void SampleLevel::handle_events(const float &delta_time) {
  if (fader.get_fade_state() != NOT_FADING)
    handle_fade(fader.get_fade_state());
  else
    handle_game_events(delta_time);
}

void SampleLevel::set_start_position_id(const std::string &start_position_id) {
  this->start_position_id = start_position_id;
}

} // namespace gs
