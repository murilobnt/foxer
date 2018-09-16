#include "character.hpp"

Character::Character(sf::Texture const &texture, sf::Vector2i sprite_pos_at_tex,
                     sf::Vector2i sprite_dimensions, sf::Vector2i animation_x,
                     sf::Vector2i animation_y, int animation_framerate)
        : gs::GameObject(texture, sprite_pos_at_tex, sprite_dimensions),
        gs::AnimatedEntity(animation_x, animation_y, animation_framerate)
        {
        movement = sf::Vector2f(0, 0);
        last_facing_pos = DOWN;
}

Character::Character() {
}

void Character::control_entity(float delta_time) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                moving_left = true;
                if(facing_position == FREE)
                        facing_position = LEFT;
        }
        else {
                moving_left = false;
                if(facing_position == LEFT) {
                        last_facing_pos = facing_position;
                        facing_position = FREE;
                }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                moving_down = true;
                if(facing_position == FREE)
                        facing_position = DOWN;
        }
        else {
                moving_down = false;
                if(facing_position == DOWN) {
                        last_facing_pos = facing_position;
                        facing_position = FREE;
                }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                moving_right = true;
                if(facing_position == FREE)
                        facing_position = RIGHT;
        }
        else {
                moving_right = false;
                if(facing_position == RIGHT) {
                        last_facing_pos = facing_position;
                        facing_position = FREE;
                }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                moving_up = true;
                if(facing_position == FREE)
                        facing_position = UP;
        }
        else {
                moving_up = false;
                if(facing_position == UP) {
                        last_facing_pos = facing_position;
                        facing_position = FREE;
                }
        }

        if(moving_left){            
            movement.x = -200 * delta_time;
        }

        if(moving_down){
            movement.y = 200 * delta_time;
        }

        if(moving_right){
            movement.x = 200 * delta_time;
        }

        if(moving_up){
            movement.y = -200 * delta_time;
        }
}

void Character::move(float delta_time){
    move_sprite(movement * delta_time);
}

void Character::move(){
    move_sprite(movement);
}

void Character::animate() {
        if (movement.x == 0.f && movement.y == 0.f) {
                switch (last_facing_pos) {
                case UP:
                        configure_sprite_rect(0, 260);
                        break;
                case DOWN:
                        configure_sprite_rect(0, 0);
                        break;
                case LEFT:
                        configure_sprite_rect(0, 130);
                        break;
                case RIGHT:
                        configure_sprite_rect(0, 390);
                        break;
                }
        }

        switch (facing_position) {
        case LEFT:
                apply_animation_by_row(this, 1);
                break;
        case RIGHT:
                apply_animation_by_row(this, 3);
                break;
        case DOWN:
                apply_animation_by_row(this, 0);
                break;
        case UP:
                apply_animation_by_row(this, 2);
                break;
        }
}
