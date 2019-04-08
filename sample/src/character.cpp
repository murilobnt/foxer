#include "character.hpp"

Character::Character(sf::Texture const &texture, sf::Vector2f position)
    : GameObject(texture, sf::Vector2i(23, 33)), AnimatedEntity(10) {
  set_sprite_position(position);
  last_facing_pos = DOWN;
  current_facing_pos = FREE;
}

Character::Character() : gs::AnimatedEntity() {}

void Character::control_entity(float delta_time) {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    moving_left = true;
    if (current_facing_pos == FREE)
      current_facing_pos = LEFT;
  } else {
    moving_left = false;
    if (current_facing_pos == LEFT) {
      last_facing_pos = current_facing_pos;
      current_facing_pos = FREE;
    }
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    moving_down = true;
    if (current_facing_pos == FREE)
      current_facing_pos = DOWN;
  } else {
    moving_down = false;
    if (current_facing_pos == DOWN) {
      last_facing_pos = current_facing_pos;
      current_facing_pos = FREE;
    }
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    moving_right = true;
    if (current_facing_pos == FREE)
      current_facing_pos = RIGHT;
  } else {
    moving_right = false;
    if (current_facing_pos == RIGHT) {
      last_facing_pos = current_facing_pos;
      current_facing_pos = FREE;
    }
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    moving_up = true;
    if (current_facing_pos == FREE)
      current_facing_pos = UP;
  } else {
    moving_up = false;
    if (current_facing_pos == UP) {
      last_facing_pos = current_facing_pos;
      current_facing_pos = FREE;
    }
  }

  if (moving_left)
    movement.x = -200 * delta_time;
  if (moving_down)
    movement.y = 200 * delta_time;
  if (moving_right)
    movement.x = 200 * delta_time;
  if (moving_up)
    movement.y = -200 * delta_time;
}

void Character::move(float delta_time) {}

void Character::move() {
  move_sprite(movement);
  movement.x = 0;
  movement.y = 0;
}

void Character::animate() {
  if (movement.x == 0.f && movement.y == 0.f) {
    switch (last_facing_pos) {
    case UP:
      configure_sprite_rect(0, 33);
      break;
    case DOWN:
      configure_sprite_rect(0, 0);
      break;
    case LEFT:
      configure_sprite_rect(0, 99);
      break;
    case RIGHT:
      configure_sprite_rect(0, 66);
      break;
    }
  }

  switch (current_facing_pos) {
  case LEFT:
    apply_animation_on_row(this, sf::Vector2i(0, 46), 99);
    break;
  case RIGHT:
    apply_animation_on_row(this, sf::Vector2i(0, 46), 66);
    break;
  case DOWN:
    apply_animation_on_row(this, sf::Vector2i(0, 69), 0);
    break;
  case UP:
    apply_animation_on_row(this, sf::Vector2i(0, 69), 33);
    break;
  }
}
