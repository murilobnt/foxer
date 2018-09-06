#include "gs2d_engine/scene/components/graphic/animated_entity.hpp"

namespace gs {

AnimatedEntity::AnimatedEntity(sf::Texture const &texture, sf::Vector2i sprite_idle_at_tex,
                               sf::Vector2i sprite_dimensions, sf::Vector2i animation_x,
                               sf::Vector2i animation_y, float animation_framerate)
        : SpritedEntity(texture, sprite_idle_at_tex, sprite_dimensions),
        animation_time_handler(sf::seconds(1.f / animation_framerate)) {
        this->animation_x = animation_x;
        this->animation_y = animation_y;

        animation_loop_state = 0;
}

AnimatedEntity::AnimatedEntity() {
}

sf::Vector2i AnimatedEntity::get_animation_x() const {
        return animation_x;
}

sf::Vector2i AnimatedEntity::get_animation_y() const {
        return animation_y;
}

TimeHandler &AnimatedEntity::get_animation_time_handler() {
        return animation_time_handler;
}

void AnimatedEntity::apply_animation(int row) {
        sf::Vector2i sprite_dimensions = get_sprite_dimensions();
        if (animation_x.x +
            animation_loop_state * sprite_dimensions.x >=
            animation_x.y)
                animation_loop_state = 0;

        configure_sprite_rect(animation_x.x +
                              animation_loop_state * sprite_dimensions.x,
                              animation_y.x +
                              row * sprite_dimensions.y);

        ++animation_loop_state;
}

}
