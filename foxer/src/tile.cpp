#include "foxer/other/helpers/tile.hpp"

namespace fox {

Tile::Tile(const sf::Vector2f &tile_position, const sf::Vector2u &tile_size) {
  this->tile_position = tile_position;

  tile_rect =
      sf::FloatRect(tile_position, sf::Vector2f(tile_size.x, tile_size.y));
}

sf::Vector2f Tile::get_position() const { return tile_position; }

float Tile::get_position_x() const { return tile_position.x; }

float Tile::get_position_y() const { return tile_position.y; }

sf::FloatRect Tile::get_tile_rect() const { return tile_rect; }

} // namespace fox
