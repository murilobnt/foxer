#include "gs2d/game/level/level.hpp"

namespace gs {

TileMap Level::get_layer(int index) const { return layers.at(index - 1); }

LayerContainer Level::get_layers(int from, int to) const {
  return LayerContainer(
      std::vector<TileMap>(layers.begin() + from - 1, layers.begin() + to));
}

LayerContainer Level::get_layers() const { return LayerContainer(layers); }

void Level::change_level(Level *level) {
  bundle->level_proxy->change_level(level);
}

void Level::change_level(std::shared_ptr<Level> level) {
  bundle->level_proxy->change_level(level);
}

void Level::set_level_bundle(LevelBundle *bundle) {
  this->bundle = bundle;
  tex_holder = TextureHolder(bundle->shared_holder);
  camera = bundle->camera;
}

} // namespace gs
