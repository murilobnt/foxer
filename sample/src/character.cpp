#include "character.hpp"

Character::Character(sf::Texture const &texture, sf::Vector2f position)
    : fox::MainObject::MainObject(texture, 5, sf::Vector2i(16, 23)),
    falling(false),
    jump_height(32),
    z_movement(0) {
  set_sprite_position(position);
  player_position = sf::Vector3f(position.x, position.y, 0);
  current_facing_pos = DOWN;
  collision_offset_down = 3;
  collision_offset_up = 22;
  collision_offset_right = 3;
  collision_offset_left = 3;
}

Character::Character() {}

void Character::jump(const float &delta_time){
  z_movement = sqrt(2 * 32 * delta_time * jump_height);
  movement.y = -z_movement;
  player_position.z += z_movement;
  player_position.y = get_sprite_position().y;
}

void Character::control_entity(float delta_time) {
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !falling){
    falling = true;
    jump(delta_time);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
      sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    moving_left = true;
    current_facing_pos = LEFT;
  } else
    moving_left = false;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
      sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
    moving_right = true;
    current_facing_pos = RIGHT;
  } else
    moving_right = false;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
      sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    moving_down = true;
    current_facing_pos = DOWN;
  } else
    moving_down = false;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
      sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    moving_up = true;
    current_facing_pos = UP;
  } else
    moving_up = false;

  if (moving_left)
    movement.x = round(-100 * delta_time);
  if (moving_down)
    movement.y = round(100 * delta_time);
  if (moving_right)
    movement.x = round(100 * delta_time);
  if (moving_up)
    movement.y = round(-100 * delta_time);

  if ((moving_up || moving_down || moving_left || moving_right) &&
      !do_animate) {
    do_animate = true;
    reset_last_update();
    set_animation_loop_state(1);
    ready_to_update();
  }
}

void Character::move(float delta_time) {
  if(falling){
    z_movement -= 32 * delta_time;
    if(player_position.z + z_movement <= 0){
      z_movement = -player_position.z;
      falling = false;
    }
    player_position.z += z_movement;
    movement.y += -z_movement;
  }
  move_sprite(movement);
  current_movement = movement;
  movement.x = 0;
  movement.y = 0;
}

void Character::move() {
}

void Character::animate() {
  if (movement.x == 0.f && movement.y == 0.f) {
    do_animate = false;
    switch (current_facing_pos) {
    case UP:
      configure_sprite_rect(0, 68);
      break;
    case DOWN:
      configure_sprite_rect(0, 5);
      break;
    case LEFT:
      configure_sprite_rect(0, 101);
      break;
    case RIGHT:
      configure_sprite_rect(0, 37);
      break;
    }
    return;
  }

  switch (current_facing_pos) {
  case LEFT:
    apply_animation_on_row(this, sf::Vector2i(0, 64), 101);
    break;
  case RIGHT:
    apply_animation_on_row(this, sf::Vector2i(0, 64), 37);
    break;
  case DOWN:
    apply_animation_on_row(this, sf::Vector2i(0, 64), 5);
    break;
  case UP:
    apply_animation_on_row(this, sf::Vector2i(0, 64), 68);
    break;
  }
}
