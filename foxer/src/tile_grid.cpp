#include "foxer/other/helpers/tile_grid.hpp"

namespace fox {

void TileGrid::check_boundaries(sf::Vector2i &before) const {
  if (before.x < 0)
    before.x = 0;

  if (before.x > x_cells)
    before.x = x_cells;

  if (before.y < 0)
    before.y = 0;

  if (before.y > y_cells)
    before.y = y_cells;
}

void TileGrid::add_unity(std::vector<Unity> &adjacent, std::set<int> &added,
                         int index) const {
  if (added.find(index) == added.end()) {
    adjacent.push_back(index >= (x_cells * y_cells)
                           ? unities[x_cells * y_cells - 1]
                           : unities[index]);
    added.insert(index);
  }
}

sf::Vector2i TileGrid::transform_to_grid_coordinate(const sf::Vector2f &spl,
                                                    int modifier_x,
                                                    int modifier_y) const {
  sf::Vector2i to_return((int)(spl.x + modifier_x) / unity_size,
                         (int)(spl.y + modifier_y) / unity_size);
  check_boundaries(to_return);
  return to_return;
}

TileGrid::TileGrid() {}

TileGrid::TileGrid(sf::Vector2u tile_size, sf::Vector2u level_size,
                   int unity_size)
    : GenericGrid::GenericGrid(level_size.x, level_size.y, unity_size) {
  this->tile_size = tile_size;
  unities.resize(x_cells * y_cells);
}

Unity *TileGrid::get_unity(int x, int y) {
  if (x + y * x_cells < x_cells * y_cells)
    return &unities[x + y * x_cells];
  else
    return &unities[(x_cells * y_cells) - 1];
}

void TileGrid::add_tile(Tile tile) {
  int tileX = tile.get_position_x();
  int tileY = tile.get_position_y();

  sf::Vector2i ul =
      sf::Vector2i((int)tileX / unity_size, (int)tileY / unity_size);
  sf::Vector2i ll = sf::Vector2i((int)tileX / unity_size,
                                 (int)(tileY + tile_size.y) / unity_size);
  sf::Vector2i ur = sf::Vector2i((int)(tileX + tile_size.x) / unity_size,
                                 (int)tileY / unity_size);
  sf::Vector2i lr = sf::Vector2i((int)(tileX + tile_size.x) / unity_size,
                                 (int)(tileY + tile_size.y) / unity_size);

  Unity *unity_ul = get_unity(ul.x, ul.y);
  Unity *unity_ll = get_unity(ll.x, ll.y);
  Unity *unity_ur = get_unity(ur.x, ur.y);
  Unity *unity_lr = get_unity(lr.x, lr.y);

  unity_ul->tiles.push_back(tile);

  if (unity_ll != unity_ul)
    unity_ll->tiles.push_back(tile);

  if (unity_ur != unity_ll && unity_ur != unity_ul)
    unity_ur->tiles.push_back(tile);

  if (unity_lr != unity_ur && unity_lr != unity_ll && unity_lr != unity_ul)
    unity_lr->tiles.push_back(tile);
}

const std::vector<Unity>
TileGrid::get_unities_in_position(const sf::Vector2f &sprite_pos,
                                  const sf::FloatRect &gb) const {
  std::vector<Unity> adjacent;
  std::set<int> added;

  sf::Vector2i center = transform_to_grid_coordinate(sprite_pos);
  sf::Vector2i up = transform_to_grid_coordinate(sprite_pos, 0, -gb.height);
  sf::Vector2i down =
      transform_to_grid_coordinate(sprite_pos, 0, gb.height * 2);
  sf::Vector2i right = transform_to_grid_coordinate(sprite_pos, gb.width * 2);
  sf::Vector2i left = transform_to_grid_coordinate(sprite_pos, -gb.width);
  sf::Vector2i up_left =
      transform_to_grid_coordinate(sprite_pos, -gb.width, -gb.height);
  sf::Vector2i up_right =
      transform_to_grid_coordinate(sprite_pos, gb.width * 2, -gb.height);
  sf::Vector2i down_left =
      transform_to_grid_coordinate(sprite_pos, -gb.width, gb.height * 2);
  sf::Vector2i down_right =
      transform_to_grid_coordinate(sprite_pos, gb.width * 2, gb.height * 2);

  add_unity(adjacent, added, center.x + center.y * x_cells);
  add_unity(adjacent, added, up.x + up.y * x_cells);
  add_unity(adjacent, added, down.x + down.y * x_cells);
  add_unity(adjacent, added, right.x + right.y * x_cells);
  add_unity(adjacent, added, left.x + left.y * x_cells);
  add_unity(adjacent, added, up_left.x + up_left.y * x_cells);
  add_unity(adjacent, added, up_right.x + up_right.y * x_cells);
  add_unity(adjacent, added, down_left.x + down_left.y * x_cells);
  add_unity(adjacent, added, down_right.x + down_right.y * x_cells);

  return adjacent;
}

} // namespace fox
