#ifndef LEVEL_TWO_HPP
#define LEVEL_TWO_HPP

#include "common_level.hpp"
#include "sample_bundle.hpp"
#include "sample_exit_area.hpp"
#include "sample_level.hpp"

#include <gs2d/game/level/components/exit_area.hpp>
#include <gs2d/game/level/components/exit_callbackable.hpp>
#include <gs2d/other/geared_up/sample_level.hpp>
#include <gs2d/scene/components/graphic/sprited_entity.hpp>

class LevelOne;

class LevelTwo : public SampleLevel, public gs::ExitCallbackable {
private:
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  void level_init();

public:
  LevelTwo();
  LevelTwo(gs::LevelBundle *bundle, SampleBundle *s_bundle, bool load = false,
           bool fade_in = true);

  void adjust_camera();
  void exit_callback(const float &delta_time, const int &pos);
};

#endif
