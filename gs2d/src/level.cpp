#include "gs2d/game/level/level.hpp"

namespace gs {

TileMap Level::get_layer(int index) const { return layers.at(index - 1); }

LayerContainer Level::get_layers(int from, int to) const {
  return LayerContainer(
      std::vector<TileMap>(layers.begin() + from - 1, layers.begin() + to));
}

} // namespace gs
