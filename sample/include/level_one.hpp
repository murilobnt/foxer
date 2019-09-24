#ifndef LEVEL_ONE_HPP
#define LEVEL_ONE_HPP

#include "common_level.hpp"
#include "level_two.hpp"
#include "sample_bundle.hpp"
#include "sample_exit_area.hpp"
#include "sample_level.hpp"

#include <gs2d/game/level/components/exit_callbackable.hpp>
#include <gs2d/other/geared_up/sample_level.hpp>

class LevelOne : public SampleLevel, public gs::ExitCallbackable {
private:
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  void level_init();

public:
  LevelOne();
  LevelOne(gs::LevelBundle *bundle, SampleBundle *s_bundle,
           const std::string &start_position_id, bool load = false,
           bool fade_in = true);
  LevelOne(gs::LevelBundle *bundle, SampleBundle *s_bundle, bool load = false,
           bool fade_in = true);
  void exit_callback(const float &delta_time, const int &pos);
};

#endif
