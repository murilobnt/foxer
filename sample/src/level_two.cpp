#include "level_one.hpp"
#include "level_two.hpp"

LevelTwo::LevelTwo() : fox::RPGLevel("assets/levels/level03.json") {}

void LevelTwo::level_init() {
  add_exit_area(std::make_unique<SampleExitArea>(
      0, this, events.find("level_change")->second,
      build_level(std::make_shared<LevelOne>())));
  initialise_camera();
}

void LevelTwo::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  if (fader.get_fade_state() != fox::NOT_FADING) {
    target.draw(get_layers(1, 4));
    target.draw(fader);
    target.draw(*player);
  } else {
    target.draw(get_layers(1, 4));
    target.draw(*player);
  }
}

void LevelTwo::exit_callback(const float &delta_time, const int &pos) {
  if (pos == 0) {
    stop_player(delta_time);
    fader.start_fade_out();
    loader = exit_areas.at(0)->get_loader();
  }
}
