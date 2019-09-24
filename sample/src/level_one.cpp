#include "level_one.hpp"

LevelOne::LevelOne() {}

LevelOne::LevelOne(gs::LevelBundle *bundle, SampleBundle *s_bundle,
                   const std::string &start_position_id, bool load,
                   bool fade_in)
    : SampleLevel(bundle, s_bundle, "assets/levels/level01.json",
                  start_position_id, load, fade_in) {}

LevelOne::LevelOne(gs::LevelBundle *bundle, SampleBundle *s_bundle, bool load,
                   bool fade_in)
    : SampleLevel(bundle, s_bundle, "assets/levels/level01.json", load,
                  fade_in) {}

void LevelOne::level_init() {
  add_exit_area(std::make_unique<SampleExitArea>(
      0, this, events.find("level_change")->second,
      std::make_shared<LevelTwo>(bundle, s_bundle)));
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

void LevelOne::exit_callback(const float &delta_time, const int &pos) {
  if (pos == 0) {
    stop_character(character, camera, delta_time);
    fader.start_fade_out();
    loader = exit_areas.at(0)->get_loader();
  }
}
