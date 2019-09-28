#include "level_one.hpp"

LevelOne::LevelOne() : RPGLevelIndoor("assets/levels/level01.json") {}

LevelOne::LevelOne(const std::string &start_position_id)
    : RPGLevelIndoor("assets/levels/level01.json", start_position_id) {}

void LevelOne::level_init() {
  add_exit_area(std::make_unique<SampleExitArea>(
      0, this, events.find("level_change")->second,
      build_level(std::make_shared<LevelTwo>())));
  initialise_camera();
}

void LevelOne::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  if (fader.get_fade_state() != gs::NOT_FADING) {
    target.draw(get_layers(1, 4));
    target.draw(fader);
    target.draw(*player);
  } else {
    target.draw(get_layers(1, 3));
    target.draw(*player);
    target.draw(get_layer(4));
  }
}

void LevelOne::exit_callback(const float &delta_time, const int &pos) {
  if (pos == 0) {
    stop_player(delta_time);
    fader.start_fade_out();
    loader = exit_areas.at(0)->get_loader();
  }
}
