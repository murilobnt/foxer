#include "gs2d/game/level/level.hpp"

namespace gs {

Level::Level(SharedTextureHolder *shared_holder)
    : shared_holder(shared_holder), tex_holder(shared_holder) {}

TileMap Level::get_layer(int index) const { return layers.at(index - 1); }

LayerContainer Level::get_layers(int from, int to) const {
  return LayerContainer(
      std::vector<TileMap>(layers.begin() + from - 1, layers.begin() + to));
}

LayerContainer Level::get_layers() const { return LayerContainer(layers); }

void Level::set_level_proxy(LevelProxy *level_proxy) {
  this->level_proxy = level_proxy;
}

void Level::change_level(Level *level) { level_proxy->change_level(level); }

void Level::change_level(std::shared_ptr<Level> level) {
  level_proxy->change_level(level);
}

} // namespace gs
