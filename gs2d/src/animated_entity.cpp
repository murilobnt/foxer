#include "gs2d/scene/components/graphic/animated_entity.hpp"

namespace gs {

AnimatedEntity::AnimatedEntity(sf::Vector2i animation_x,
                               sf::Vector2i animation_y,
                               float animation_framerate)
    : TimedEntity(sf::seconds(1.f / animation_framerate)) {
  this->animation_x = animation_x;
  this->animation_y = animation_y;

  animation_loop_state = 0;
}

AnimatedEntity::AnimatedEntity() {}

sf::Vector2i AnimatedEntity::get_animation_x() const { return animation_x; }

sf::Vector2i AnimatedEntity::get_animation_y() const { return animation_y; }

void AnimatedEntity::apply_animation_by_row(SpritedEntity *sprited_entity,
                                            int row) {
  sf::Vector2i sprite_dimensions = sprited_entity->get_sprite_dimensions();
  if (animation_x.x + animation_loop_state * sprite_dimensions.x >=
      animation_x.y)
    animation_loop_state = 0;

  sprited_entity->configure_sprite_rect(
      animation_x.x + animation_loop_state * sprite_dimensions.x,
      animation_y.x + row * sprite_dimensions.y);

  ++animation_loop_state;
}

void AnimatedEntity::on_update_time() { animate(); }

} // namespace gs
