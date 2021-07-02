#include "foxer/logical/tiled_level_data.hpp"

namespace fox {

const std::vector<TileMap> &TiledLevelData::get_layers() const {
  return layers;
}

const std::unique_ptr<TileGrid> &TiledLevelData::get_collision_tile_grid() const {
  return collision_tile_grid;
}

const std::map<std::string, TiledJsonObj> &TiledLevelData::get_events() const {
  return events;
}

const sf::Vector2u &TiledLevelData::get_tile_size() const {
  return tile_size;
}

const sf::Vector2u &TiledLevelData::get_level_size() const {
  return level_size;
}

TiledLevelData::TiledLevelData() {}

TiledLevelData::TiledLevelData(const sf::Vector2u &tile_size,
               const sf::Vector2u &level_size,
               const std::vector<TileMap> &layers,
               std::unique_ptr<TileGrid> collision_tile_grid,
               const std::map<std::string, TiledJsonObj> &events) :
               layers(layers),
               collision_tile_grid(std::move(collision_tile_grid)),
               events(events),
               tile_size(tile_size),
               level_size(level_size)
{

}

} // namespace fox
