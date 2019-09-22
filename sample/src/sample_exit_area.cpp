#include "sample_exit_area.hpp"

SampleExitArea::SampleExitArea() {}

void SampleExitArea::verify_collision_with(gs::SpritedEntity *entity,
                                           const float &delta_time) {
  sf::FloatRect char_rect = entity->get_sprite_global_bounds();
  char_rect.height -= 22;
  char_rect.top += 15;

  if (collides_with(char_rect))
    on_collision(delta_time);
}

void SampleExitArea::on_collision(const float &delta_time) {
  callbackable->exit_callback(delta_time);
}

void SampleExitArea::set_callbackable(gs::ExitCallbackable *callbackable) {
  this->callbackable = callbackable;
}

void SampleExitArea::_load(gs::ExitCallbackable *callbackable,
                           const gs::TiledJsonObj &exit_json,
                           std::shared_ptr<gs::SampleLevel> next_level,
                           const std::string &field) {
  this->callbackable = callbackable;
  exit_load(exit_json, next_level, field);
}
