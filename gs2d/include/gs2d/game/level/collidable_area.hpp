#ifndef GS_COLLIDABLE_AREA_HPP
#define GS_COLLIDABLE_AREA_HPP

#include <SFML/Graphics.hpp>
#include <gs2d/game/level/tiled_json_container.hpp>

namespace gs {

class CollidableArea {
private:
  sf::FloatRect area;

protected:
  void load(const sf::FloatRect &area);

public:
  CollidableArea();
  explicit CollidableArea(const sf::FloatRect &area);
  bool collides_with(const sf::FloatRect &rect);
};

} // namespace gs

#endif
