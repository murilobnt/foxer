#include "level_one.hpp"
#include "level_two.hpp"

LevelTwo::LevelTwo() {}

LevelTwo::LevelTwo(gs::LevelBundle *bundle, SampleBundle *s_bundle, bool load,
                   bool fade_in)
    : SampleLevel(bundle, s_bundle, "assets/levels/level03.json", load,
                  fade_in) {}

void LevelTwo::level_init() {
  add_exit_area(std::make_unique<SampleExitArea>(
      0, this, events.find("level_change")->second,
      std::make_shared<LevelOne>(bundle, s_bundle)));
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

void LevelTwo::adjust_camera() {
  CommonLevel::adjust_camera(camera, level_size, tile_size);
}

void LevelTwo::exit_callback(const float &delta_time, const int &pos) {
  if (pos == 0) {
    stop_character(character, camera, delta_time);
    fader.start_fade_out();
    loader = exit_areas.at(0)->get_loader();
  }
}
