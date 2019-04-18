#include "gs2d/game/level/exit_area.hpp"

namespace gs {

ExitArea::ExitArea() {}

ExitArea::ExitArea(const gs::TiledJsonObj &exit_json, const std::string &field)
    : CollidableArea::CollidableArea(sf::FloatRect(
          exit_json.x, exit_json.y, exit_json.width, exit_json.height)) {
  exit_load(exit_json, field);
}

void ExitArea::exit_load(const gs::TiledJsonObj &exit_json,
                         const std::string &field) {
  load(sf::FloatRect(exit_json.x, exit_json.y, exit_json.width,
                     exit_json.height));
  destination_id = exit_json.properties[field].get<std::string>();
}

std::string ExitArea::get_destination_id() const { return destination_id; }

} // namespace gs
