#ifndef SAMPLE_LEVEL_HPP
#define SAMPLE_LEVEL_HPP

#include <gs2d/other/geared_up/sample_level.hpp>
#include <memory>
#include <vector>

#include "common_level.hpp"
#include "sample_bundle.hpp"
#include "sample_exit_area.hpp"

class SampleLevel : public gs::SampleLevel, public CommonLevel {
protected:
  std::vector<std::unique_ptr<gs::ExitArea>> exit_areas;
  SampleBundle *s_bundle;

  void add_exit_area(std::unique_ptr<SampleExitArea> area);

public:
  SampleLevel();
  SampleLevel(gs::LevelBundle *bundle, SampleBundle *s_bundle,
              const std::string &json_path,
              const std::string &start_position_id, bool load, bool fade_in);
  SampleLevel(gs::LevelBundle *bundle, SampleBundle *s_bundle,
              const std::string &json_path, bool load, bool fade_in);
  void on_fade_out();
  void on_fade_in();
  void handle_level_events(const float &delta_time);
  void control_camera(const float &delta_time);
  virtual void adjust_camera();
};

#endif
