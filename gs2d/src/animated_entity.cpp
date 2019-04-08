#include "gs2d/scene/components/graphic/animated_entity.hpp"

namespace gs {

AnimatedEntity::AnimatedEntity(float animation_framerate)
    : TimedEntity(sf::seconds(1.f / animation_framerate)),
      animation_loop_state(0) {}

AnimatedEntity::AnimatedEntity() {}

void AnimatedEntity::apply_animation_on_row(SpritedEntity *sprited_entity,
                                            sf::Vector2i anim_x, int anim_y) {
  sf::Vector2i sprite_dimensions = sprited_entity->get_sprite_dimensions();
  if (anim_x.x + animation_loop_state * sprite_dimensions.x >= anim_x.y)
    animation_loop_state = 0;

  sprited_entity->configure_sprite_rect(
      anim_x.x + animation_loop_state * sprite_dimensions.x, anim_y);

  ++animation_loop_state;
}

void AnimatedEntity::apply_animation_on_column(SpritedEntity *sprited_entity,
                                               int anim_x,
                                               sf::Vector2i anim_y) {
  sf::Vector2i sprite_dimensions = sprited_entity->get_sprite_dimensions();
  if (anim_y.x + animation_loop_state * sprite_dimensions.y >= anim_y.y)
    animation_loop_state = 0;

  sprited_entity->configure_sprite_rect(
      anim_x, anim_y.x + animation_loop_state * sprite_dimensions.y);

  ++animation_loop_state;
}

void AnimatedEntity::on_update_time() { animate(); }

} // namespace gs
