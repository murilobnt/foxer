#include "gs2d/game/level/layer_container.hpp"

namespace gs {

LayerContainer::LayerContainer(std::vector<TileMap> tile_layers)
    : tile_layers(tile_layers) {}

void LayerContainer::draw(sf::RenderTarget &target,
                          sf::RenderStates states) const {
  for (int i = 0; i < tile_layers.size(); ++i)
    target.draw(tile_layers.at(i), states);
}

} // namespace gs
