#ifndef GS_RPG_LEVEL_HPP
#define GS_RPG_LEVEL_HPP

#include <memory>
#include <vector>

#include "gs2d/game/level/components/exit_area.hpp"
#include "gs2d/other/geared_up/sample_level.hpp"

namespace gs {

class RPGLevel : public SampleLevel {
private:
  sf::Vector2f *delay;

protected:
  std::vector<std::unique_ptr<ExitArea>> exit_areas;
  void add_exit_area(std::unique_ptr<ExitArea> area);

public:
  RPGLevel();
  explicit RPGLevel(const std::string &json);
  RPGLevel(const std::string &json, const std::string &start_position_id);

  virtual void on_fade_out();
  virtual void on_fade_in();
  virtual void handle_level_events(const float &delta_time);
  virtual void control_camera(const float &delta_time);

  void stop_player(const float &delta_time);
  void initialise_camera();
  void adjust_camera();
  void _change_level(std::shared_ptr<RPGLevel> level);

  void set_delay(sf::Vector2f *delay);
  std::shared_ptr<RPGLevel> make_level(std::shared_ptr<RPGLevel> level);
};

}; // namespace gs

#endif
