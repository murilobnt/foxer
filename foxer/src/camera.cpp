#include "foxer/components/camera.hpp"

namespace fox {

Camera::Camera(sf::Vector2f const camera_center_position,
               sf::Vector2f const camera_dimensions)
    : view(camera_center_position, camera_dimensions) {}

Camera::Camera(sf::Vector2f const camera_center_position,
               sf::Vector2f const camera_dimensions, float const zoom)
    : view(camera_center_position, camera_dimensions) {
  view.zoom(zoom);
}

Camera::Camera(sf::Vector2f const camera_dimensions)
    : view(sf::Vector2f(0, 0), camera_dimensions) {}

Camera::Camera(sf::Vector2f const camera_dimensions, float const zoom)
    : view(sf::Vector2f(0, 0), camera_dimensions) {
  view.zoom(zoom);
}

Camera::Camera() {}

void Camera::apply_zoom(float const zoom) { view.zoom(zoom); }

void Camera::center_at_sprite(const sf::Sprite &sprite) {
  sf::FloatRect global_bounds = sprite.getGlobalBounds();
  sf::Vector2f sprite_position = sprite.getPosition();
  view.setCenter(sprite_position.x + global_bounds.width / 2,
                 sprite_position.y + global_bounds.height / 2);
}

void Camera::center_at_sprite(const sf::Sprite &sprite,
                              const sf::Vector2u &level_size) {
  sf::Vector2f sprite_position = sprite.getPosition();
  sf::FloatRect global_bounds = sprite.getGlobalBounds();
  sf::Vector2f final_position =
      sf::Vector2f(sprite_position.x + global_bounds.width / 2,
                   sprite_position.y + global_bounds.height / 2);
  sf::Vector2f view_size = view.getSize();

  if (sprite_position.x + (global_bounds.width / 2) - view_size.x < 0)
    final_position.x = view_size.x;

  if (sprite_position.y + (global_bounds.height / 2) - view_size.y < 0)
    final_position.y = view_size.y;

  if (sprite_position.x + (global_bounds.width / 2) + view_size.x >
      level_size.x)
    final_position.x = level_size.x - view_size.x;

  if (sprite_position.y + (global_bounds.height / 2) + view_size.y >
      level_size.y)
    final_position.y = level_size.y - view_size.y;

  view.setCenter(final_position);
}

void Camera::center_at_position(sf::Vector2f position) {
  view.setCenter(position);
}

sf::Vector2f Camera::get_center() const { return view.getCenter(); }

sf::View Camera::get_view() const { return view; }

sf::Vector2f Camera::get_size() const { return view.getSize(); }

void Camera::move(sf::Vector2f movement) { view.move(movement); }

} // namespace fox
