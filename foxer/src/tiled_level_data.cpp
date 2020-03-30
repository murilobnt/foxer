#include "foxer/game/level/tiled_level_data.hpp"

namespace fox {

const std::vector<TileMap> &TiledLevelData::get_layers() const{
  return layers;
}

const TileGrid &TiledLevelData::get_collision_tile_grid() const{
  return collision_tile_grid;
}

const TileGrid *TiledLevelData::get_collision_tile_grid_ref() const{
  return &collision_tile_grid;
}

const std::map<std::string, TiledJsonObj> &TiledLevelData::get_events() const{
  return events;
}

TiledLevelData::TiledLevelData() {}

TiledLevelData::TiledLevelData(std::vector<TileMap> layers,
               TileGrid collision_tile_grid,
               std::map<std::string, TiledJsonObj> events) :
               layers(layers),
               collision_tile_grid(collision_tile_grid),
               events(events){

}

} // namespace fox
