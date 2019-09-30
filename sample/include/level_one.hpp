#ifndef LEVEL_ONE_HPP
#define LEVEL_ONE_HPP

#include <foxer/game/level/components/exit_callbackable.hpp>
#include <foxer/other/geared_up/rpg_level_indoor.hpp>

#include "level_two.hpp"
#include "sample_exit_area.hpp"

class LevelOne : public fox::RPGLevelIndoor, public fox::ExitCallbackable {
private:
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  void level_init();

public:
  LevelOne();
  explicit LevelOne(const std::string &start_position_id);
  void exit_callback(const float &delta_time, const int &pos);
};

#endif
