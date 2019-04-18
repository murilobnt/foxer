#include "gs2d/game/level/collidable_area.hpp"

namespace gs {

CollidableArea::CollidableArea() {}

CollidableArea::CollidableArea(const sf::FloatRect &area) { this->area = area; }

void CollidableArea::load(const sf::FloatRect &area) { this->area = area; }

bool CollidableArea::collides_with(const sf::FloatRect &rect) {
  return area.intersects(rect);
}

} // namespace gs
