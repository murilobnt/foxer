#include "gs2d_engine/scene/components/camera/camera.hpp"

namespace gs {

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

void Camera::center_at_position(sf::Vector2f position) {
  view.setCenter(position);
}

sf::View Camera::get_view() const { return view; }

} // namespace gs
