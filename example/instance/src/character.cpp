#include "character.hpp"

Character::Character(sf::Texture const &texture, sf::Vector2i sprite_pos_at_tex,
                     sf::Vector2i sprite_dimensions, sf::Vector2i animation_x,
                     sf::Vector2i animation_y, int animation_framerate)
        : gs::AnimatedEntity(
                texture, sprite_pos_at_tex, sprite_dimensions,
                animation_x, animation_y, animation_framerate) {
        movement = sf::Vector2f(0, 0);
        last_facing_pos = DOWN;
        current_facing_pos = FREE;
        moving_up = false;
        moving_down = false;
        moving_left = false;
        moving_right = false;
}

Character::Character() : gs::AnimatedEntity() {
}

void Character::control_entity() {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                moving_left = true;
                if(current_facing_pos == FREE)
                        current_facing_pos = LEFT;
        }
        else {
                moving_left = false;
                if(current_facing_pos == LEFT) {
                        last_facing_pos = current_facing_pos;
                        current_facing_pos = FREE;
                }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                moving_down = true;
                if(current_facing_pos == FREE)
                        current_facing_pos = DOWN;
        }
        else {
                moving_down = false;
                if(current_facing_pos == DOWN) {
                        last_facing_pos = current_facing_pos;
                        current_facing_pos = FREE;
                }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                moving_right = true;
                if(current_facing_pos == FREE)
                        current_facing_pos = RIGHT;
        }
        else {
                moving_right = false;
                if(current_facing_pos == RIGHT) {
                        last_facing_pos = current_facing_pos;
                        current_facing_pos = FREE;
                }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                moving_up = true;
                if(current_facing_pos == FREE)
                        current_facing_pos = UP;
        }
        else {
                moving_up = false;
                if(current_facing_pos == UP) {
                        last_facing_pos = current_facing_pos;
                        current_facing_pos = FREE;
                }
        }

        if(moving_left)
                movement.x = -2;
        if(moving_down)
                movement.y = 2;
        if(moving_right)
                movement.x = 2;
        if(moving_up)
                movement.y = -2;
}

void Character::move_character() {
        move_sprite(movement);
        movement.x = 0;
        movement.y = 0;
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

        switch (current_facing_pos) {
        case LEFT:
                apply_animation(1);
                break;
        case RIGHT:
                apply_animation(3);
                break;
        case DOWN:
                apply_animation(0);
                break;
        case UP:
                apply_animation(2);
                break;
        }
}
