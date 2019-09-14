#ifndef LEVEL_ONE_HPP
#define LEVEL_ONE_HPP

#include "level_two.hpp"
#include <gs2d/game/level/exit_area.hpp>
#include <gs2d/other/geared_up/sample_level.hpp>

class LevelOne : public gs::SampleLevel {
private:
  gs::Camera *camera;
  sf::Vector2f *delay;

  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  gs::ExitArea exit;
  gs::ThreadedLevelLoader level_two_loader;

  void on_fade_out();
  void on_fade_in();
  void handle_level_events(const float &delta_time);
  void level_init();

public:
  LevelOne();
  LevelOne(gs::LevelProxy *level_proxy, gs::MainObject *character,
           const std::string &start_position_id, gs::Camera *camera,
           sf::Vector2f *delay, bool fade_in = true);
};

#endif
