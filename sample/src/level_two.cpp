#include "level_one.hpp"
#include "level_two.hpp"

LevelTwo::LevelTwo() {}

LevelTwo::LevelTwo(gs::LevelBundle *bundle, SampleBundle *s_bundle, bool load,
                   bool fade_in)
    : gs::SampleLevel(bundle, s_bundle->character, "assets/levels/level03.json",
                      load, fade_in),
      CommonLevel(s_bundle->delay), s_bundle(s_bundle) {}

void LevelTwo::level_init() {
  m_exit._load(this, events.find("level_change")->second,
               std::make_shared<LevelOne>(bundle, s_bundle));
  initialise_camera(character, camera, fading_speed);
}

void LevelTwo::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  if (fader.get_fade_state() != gs::NOT_FADING) {
    target.draw(get_layers(1, 4));
    target.draw(fader);
    target.draw(*character);
  } else {
    target.draw(get_layers(1, 4));
    target.draw(*character);
  }
}

void LevelTwo::handle_level_events(const float &delta_time) {
  m_exit.verify_collision_with(character, delta_time);
}

void LevelTwo::on_fade_out() { change_level(loader->get_level()); }

void LevelTwo::on_fade_in() {}

void LevelTwo::control_camera(const float &delta_time) {
  camera->move(
      sf::Vector2f((character->get_sprite_position() - camera->get_center())) *
      (delta_time * 5));

  adjust_camera(camera, level_size, tile_size);
}

void LevelTwo::exit_callback(const float &delta_time) {
  stop_character(character, camera, delta_time);
  fader.start_fade_out();
  loader = m_exit.get_loader();
}
