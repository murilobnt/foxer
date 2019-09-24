#ifndef SAMPLE_EXIT_AREA_HPP
#define SAMPLE_EXIT_AREA_HPP

#include <SFML/Graphics.hpp>
#include <gs2d/game/level/components/exit_area.hpp>
#include <gs2d/game/level/components/exit_callbackable.hpp>

class SampleExitArea : public gs::ExitArea {
private:
  gs::ExitCallbackable *callbackable;
  int pos;

public:
  SampleExitArea();
  SampleExitArea(const int &pos, gs::ExitCallbackable *callbackable,
                 const gs::TiledJsonObj &exit_json,
                 std::shared_ptr<gs::SampleLevel> next_level,
                 const std::string &field = "destination");

  void set_callbackable(gs::ExitCallbackable *callbackable);
  void _load(const int &pos, gs::ExitCallbackable *callbackable,
             const gs::TiledJsonObj &exit_json,
             std::shared_ptr<gs::SampleLevel> next_level,
             const std::string &field = "destination");

  void verify_collision_with(gs::SpritedEntity *entity,
                             const float &delta_time);
  void on_collision(const float &delta_time);
};

#endif
