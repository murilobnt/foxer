#ifndef GS_RPG_LEVEL_INDOOR_HPP
#define GS_RPG_LEVEL_INDOOR_HPP

#include "gs2d/other/geared_up/rpg_level.hpp"

namespace gs {

class RPGLevelIndoor : public RPGLevel {
public:
  RPGLevelIndoor();
  explicit RPGLevelIndoor(const std::string &json);
  RPGLevelIndoor(const std::string &json, const std::string &start_position_id);
  virtual void control_camera(const float &delta_time);
};

} // namespace gs

#endif
