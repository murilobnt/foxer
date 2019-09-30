#include "foxer/game/level/components/exit_area.hpp"

namespace fox {

ExitArea::ExitArea() {}

void ExitArea::exit_load(const TiledJsonObj &exit_json,
                         std::shared_ptr<SampleLevel> next_level,
                         const std::string &field) {
  load(sf::FloatRect(exit_json.x, exit_json.y, exit_json.width,
                     exit_json.height));
  next_level->set_start_position_id(
      exit_json.properties[field].get<std::string>());
  loader.run(next_level);
}

std::string ExitArea::get_destination_id() const { return destination_id; }

void ExitArea::verify_collision_with(SpritedEntity *entity,
                                     const float &delta_time) {
  if (collides_with(entity->get_sprite_global_bounds()))
    on_collision(delta_time);
}

ThreadedLevelLoader *ExitArea::get_loader() { return &this->loader; }

} // namespace fox
