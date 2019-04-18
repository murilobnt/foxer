#ifndef LEVEL_TWO_HPP
#define LEVEL_TWO_HPP

#include "sample_level.hpp"
#include <gs2d/game/level/exit_area.hpp>

class LevelOne;

class LevelTwo : public SampleLevel {
private:
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  gs::ExitArea exit;
  gs::ThreadedLevelLoader level_one_loader;

  void on_fade_out();
  void on_fade_in();
  void handle_level_events(const float &delta_time);
  void level_init();

public:
  LevelTwo();
  LevelTwo(Character *character, gs::LevelProxy *level_proxy,
           const std::string &start_position_id, bool fade_in = true);
};

#endif
