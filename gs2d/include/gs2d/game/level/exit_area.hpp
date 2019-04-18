#ifndef GS_EXIT_AREA_HPP
#define GS_EXIT_AREA_HPP

#include <string>

#include "gs2d/game/level/collidable_area.hpp"

namespace gs {

class ExitArea : public CollidableArea {
private:
  std::string destination_id;

public:
  ExitArea();
  ExitArea(const gs::TiledJsonObj &exit_json, const std::string &field);
  void exit_load(const gs::TiledJsonObj &exit_json, const std::string &field);
  std::string get_destination_id() const;
};

} // namespace gs

#endif
