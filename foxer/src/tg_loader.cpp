#include "foxer/logical/tg_loader.hpp"

namespace fox::TGLoader {

  TileGrid load(const std::vector<int> &collision_layer,
                const sf::Vector2u &tile_size,
                const sf::Vector2u &level_size) {
    sf::Vector2u real_level_size(level_size.x * tile_size.x,
                                 level_size.y * tile_size.y);
    TileGrid tile_grid(tile_size, real_level_size, tile_size.x * 6);
    for (unsigned int i = 0; i < level_size.x; ++i)
      for (unsigned int j = 0; j < level_size.y; ++j) {
        int tile_number = collision_layer[i + j * level_size.x];
        --tile_number;

        if (tile_number == -1)
          continue;

        tile_grid.add_tile(
            Tile(sf::Vector2f(i * tile_size.x, j * tile_size.y), tile_size));
      }
    return tile_grid;
  }

}
