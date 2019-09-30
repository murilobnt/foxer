#ifndef SAMPLE_EXIT_AREA_HPP
#define SAMPLE_EXIT_AREA_HPP

#include <SFML/Graphics.hpp>
#include <foxer/game/level/components/exit_area.hpp>
#include <foxer/game/level/components/exit_callbackable.hpp>

class SampleExitArea : public fox::ExitArea {
private:
  fox::ExitCallbackable *callbackable;
  int pos;

public:
  SampleExitArea();
  SampleExitArea(const int &pos, fox::ExitCallbackable *callbackable,
                 const fox::TiledJsonObj &exit_json,
                 std::shared_ptr<fox::SampleLevel> next_level,
                 const std::string &field = "destination");

  void set_callbackable(fox::ExitCallbackable *callbackable);
  void _load(const int &pos, fox::ExitCallbackable *callbackable,
             const fox::TiledJsonObj &exit_json,
             std::shared_ptr<fox::SampleLevel> next_level,
             const std::string &field = "destination");

  void verify_collision_with(fox::SpritedEntity *entity,
                             const float &delta_time);
  void on_collision(const float &delta_time);
};

#endif
