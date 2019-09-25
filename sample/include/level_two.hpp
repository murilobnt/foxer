#ifndef LEVEL_TWO_HPP
#define LEVEL_TWO_HPP

#include <gs2d/game/level/components/exit_callbackable.hpp>
#include <gs2d/other/geared_up/rpg_level.hpp>

#include "sample_exit_area.hpp"

class LevelOne;

class LevelTwo : public gs::RPGLevel, public gs::ExitCallbackable {
private:
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  void level_init();

public:
  LevelTwo();
  void exit_callback(const float &delta_time, const int &pos);
};

#endif
