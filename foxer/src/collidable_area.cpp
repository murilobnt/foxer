#include "foxer/game/level/components/collidable_area.hpp"

namespace fox {

CollidableArea::CollidableArea() {}

CollidableArea::CollidableArea(const sf::FloatRect &area) { this->area = area; }

void CollidableArea::load(const sf::FloatRect &area) { this->area = area; }

bool CollidableArea::collides_with(const sf::FloatRect &rect) {
  return area.intersects(rect);
}

} // namespace fox
