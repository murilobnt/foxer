#include "gamesimple/components/animatedentity.hpp"

AnimatedEntity::AnimatedEntity(sf::Texture const &texture, int sprite_x,
                               int sprite_y, int sprite_w, int sprite_h,
                               int animation_initial_x_position,
                               int animation_final_x_position,
                               int animation_initial_y_position,
                               int animation_final_y_position,
                               float animation_framerate)
        : SpritedEntity::SpritedEntity(texture, sprite_x, sprite_y,
                                       sprite_w, sprite_h),
        animation_time_handler(sf::seconds(1.f / animation_framerate)) {
        this->animation_initial_x_position = animation_initial_x_position;
        this->animation_final_x_position = animation_final_x_position;
        this->animation_initial_y_position = animation_initial_y_position;
        this->animation_final_y_position = animation_final_y_position;

        animation_loop_state = 0;
}

AnimatedEntity::AnimatedEntity() {
}

int AnimatedEntity::get_animation_initial_x_position() const {
        return animation_initial_x_position;
}

int AnimatedEntity::get_animation_final_x_position() const {
        return animation_final_x_position;
}

int AnimatedEntity::get_animation_initial_y_position() const {
        return animation_initial_y_position;
}

int AnimatedEntity::get_animation_final_y_position() const {
        return animation_final_y_position;
}

TimeHandler &AnimatedEntity::get_animation_time_handler() {
        return animation_time_handler;
}

void AnimatedEntity::apply_animation(int row) {
        sf::Vector2i sprite_dimensions = get_sprite_dimensions();
        if (get_animation_initial_x_position() +
            animation_loop_state * sprite_dimensions.x >=
            get_animation_final_x_position())
                animation_loop_state = 0;

        configure_sprite_rect(get_animation_initial_x_position() +
                            animation_loop_state * sprite_dimensions.x,
                            get_animation_initial_y_position() +
                            row * sprite_dimensions.y);

        ++animation_loop_state;
}
