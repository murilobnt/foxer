#include "gs2d_engine/components/sprited_entity.hpp"

SpritedEntity::SpritedEntity(sf::Texture const &texture, int sprite_x,
                             int sprite_y, int sprite_w, int sprite_h)
        : sprite_dimensions(sprite_w, sprite_h) {
        sprite.setTexture(texture);
        configure_sprite_rect(sprite_x, sprite_y, sprite_w, sprite_h);
}

SpritedEntity::SpritedEntity() {
}

void SpritedEntity::configure_sprite_rect(int x, int y, int w, int h) {
        sprite.setTextureRect(sf::IntRect(x, y, w, h));
}

void SpritedEntity::configure_sprite_rect(int x, int y) {
        int w = sprite_dimensions.x;
        int h = sprite_dimensions.y;
        sprite.setTextureRect(sf::IntRect(x, y, w, h));
}

void SpritedEntity::set_sprite_position(sf::Vector2f position) {
        sprite.setPosition(position);
}

void SpritedEntity::set_sprite_position(float x, float y) {
        sprite.setPosition(x, y);
}

void SpritedEntity::set_sprite_scale(float x, float y) {
        sprite.setScale(x, y);
}

void SpritedEntity::move_sprite(sf::Vector2f movement) {
        sprite.move(movement);
}

void SpritedEntity::set_sprite_color(sf::Color color) {
        sprite.setColor(color);
}

sf::Sprite SpritedEntity::get_sprite() const {
        return sprite;
}

sf::Vector2f SpritedEntity::get_sprite_position() const {
        return sprite.getPosition();
}

sf::Vector2i SpritedEntity::get_sprite_dimensions() const {
        return sprite_dimensions;
}

sf::FloatRect SpritedEntity::get_sprite_global_bounds() const {
        return sprite.getGlobalBounds();
}

sf::FloatRect SpritedEntity::get_sprite_local_bounds() const {
        return sprite.getLocalBounds();
}
