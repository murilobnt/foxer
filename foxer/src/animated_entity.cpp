#include "foxer/abstract_components/animated_entity.hpp"

namespace fox {

AnimatedEntity::AnimatedEntity(float animation_framerate)
    : TimedEntity(sf::seconds(1.f / animation_framerate)),
      animation_loop_state(0) {}

AnimatedEntity::AnimatedEntity() {}

void AnimatedEntity::apply_animation_on_row(sf::Sprite *sprite,
                                            sf::Vector2i anim_x, int anim_y) {
  sf::FloatRect local_bounds = sprite->getLocalBounds();
  if (anim_x.x + animation_loop_state * local_bounds.width >= anim_x.y)
    animation_loop_state = 0;

  sprite->setTextureRect(sf::IntRect(
      anim_x.x + animation_loop_state * local_bounds.width, anim_y,
      local_bounds.width, local_bounds.height));

  ++animation_loop_state;
}

void AnimatedEntity::apply_animation_on_column(sf::Sprite *sprite,
                                               int anim_x,
                                               sf::Vector2i anim_y) {
  sf::FloatRect local_bounds = sprite->getLocalBounds();
  if (anim_y.x + animation_loop_state * local_bounds.height >= anim_y.y)
    animation_loop_state = 0;

  sprite->setTextureRect(sf::IntRect(
      anim_x, anim_y.x + animation_loop_state * local_bounds.height,
      local_bounds.width, local_bounds.height));

  ++animation_loop_state;
}

void AnimatedEntity::on_update_time() { animate(); }

void AnimatedEntity::set_animation_loop_state(const int &animation_loop_state) {
  this->animation_loop_state = animation_loop_state;
}

} // namespace fox
