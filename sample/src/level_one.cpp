#include "level_one.hpp"

LevelOne::LevelOne() {}

LevelOne::LevelOne(gs::LevelBundle *bundle, SampleBundle *s_bundle,
                   const std::string &start_position_id, bool load,
                   bool fade_in)
    : gs::SampleLevel(bundle, s_bundle->character, "assets/levels/level01.json",
                      start_position_id, load, fade_in),
      CommonLevel(s_bundle->delay), s_bundle(s_bundle) {}

LevelOne::LevelOne(gs::LevelBundle *bundle, SampleBundle *s_bundle, bool load,
                   bool fade_in)
    : gs::SampleLevel(bundle, s_bundle->character, "assets/levels/level01.json",
                      load, fade_in),
      CommonLevel(s_bundle->delay), s_bundle(s_bundle) {}

void LevelOne::level_init() {
  m_exit._load(this, events.find("level_change")->second,
               std::make_shared<LevelTwo>(bundle, s_bundle));
  initialise_camera(character, camera, fading_speed);
}

void LevelOne::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  if (fader.get_fade_state() != gs::NOT_FADING) {
    target.draw(get_layers(1, 4));
    target.draw(fader);
    target.draw(*character);
  } else {
    target.draw(get_layers(1, 3));
    target.draw(*character);
    target.draw(get_layer(4));
  }
}

void LevelOne::on_fade_out() { change_level(loader->get_level()); }

void LevelOne::on_fade_in() {}

void LevelOne::handle_level_events(const float &delta_time) {
  m_exit.verify_collision_with(character, delta_time);
}

void LevelOne::control_camera(const float &delta_time) {
  camera->move(
      sf::Vector2f((character->get_sprite_position() - camera->get_center())) *
      (delta_time * 5));
}

void LevelOne::exit_callback(const float &delta_time) {
  stop_character(character, camera, delta_time);
  fader.start_fade_out();
  loader = m_exit.get_loader();
}
