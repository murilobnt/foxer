#ifndef FOX_TG_LOADER_HPP_
#define FOX_TG_LOADER_HPP_

#include "foxer/other/helpers/tile_grid.hpp"

namespace fox::TGLoader {

  TileGrid load(const std::vector<int> &collision_layer,
                const sf::Vector2u &tile_size,
                const sf::Vector2u &level_size);

}

#endif
