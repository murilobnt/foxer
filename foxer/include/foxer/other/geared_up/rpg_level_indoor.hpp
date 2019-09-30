#ifndef FOX_RPG_LEVEL_INDOOR_HPP
#define FOX_RPG_LEVEL_INDOOR_HPP

#include "foxer/other/geared_up/rpg_level.hpp"

namespace fox {

class RPGLevelIndoor : public RPGLevel {
public:
  RPGLevelIndoor();
  explicit RPGLevelIndoor(const std::string &json);
  RPGLevelIndoor(const std::string &json, const std::string &start_position_id);
  virtual void control_camera(const float &delta_time);
};

} // namespace fox

#endif
