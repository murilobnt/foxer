#ifndef FOX_TILED_LEVEL_DATA_HPP_
#define FOX_TILED_LEVEL_DATA_HPP_

#include <map>
#include <string>
#include <vector>

#include "foxer/game/level/tiled_json_container.hpp"
#include "foxer/game/level/tilemap.hpp"
#include "foxer/other/helpers/tile_grid.hpp"

namespace fox {

class TiledLevelData {
public:
  const std::vector<TileMap> &get_layers() const;
  const TileGrid &get_collision_tile_grid() const;
  const std::map<std::string, TiledJsonObj> &get_events() const;

  TiledLevelData();
  TiledLevelData(std::vector<TileMap> layers,
                 TileGrid collision_tile_grid,
                 std::map<std::string, TiledJsonObj> events);

private:
  std::vector<TileMap> layers;
  TileGrid collision_tile_grid;
  std::map<std::string, TiledJsonObj> events;
};

} // namespace fox

#endif
