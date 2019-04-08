#include "gs2d/game/level/tiled_layer_container.hpp"

namespace gs {

void TiledLayerContainer::add_layer(TileMap tilemap) {
  tile_layers.push_back(tilemap);
}

void TiledLayerContainer::draw(sf::RenderTarget &target,
                                sf::RenderStates states) const {
  for (int i = 0; i < tile_layers.size(); ++i)
    target.draw(tile_layers.at(i), states);
}

} // namespace gs
