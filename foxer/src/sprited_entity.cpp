#include "foxer/components/sprited_entity.hpp"

namespace fox {

SpritedEntity::SpritedEntity(sf::Texture const &texture,
                             sf::Vector2i sprite_dimensions,
                             sf::Vector2i sprite_pos_at_tex)
    : sprite_dimensions(sprite_dimensions) {
  sprite.setTexture(texture);
  configure_sprite_rect(sprite_pos_at_tex.x, sprite_pos_at_tex.y);
}

SpritedEntity::SpritedEntity() {}

void SpritedEntity::draw(sf::RenderTarget &target,
                         sf::RenderStates states) const {
  target.draw(sprite);
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

sf::Sprite SpritedEntity::get_sprite() const { return sprite; }

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

sf::RectangleShape SpritedEntity::get_rectangle_shape() const {
  sf::FloatRect gb = sprite.getGlobalBounds();
  sf::RectangleShape to_return(sf::Vector2f(gb.width, gb.height));
  to_return.setPosition(sprite.getPosition());
  return to_return;
}

} // namespace fox
