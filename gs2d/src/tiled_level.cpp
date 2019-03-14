#include "gs2d/game/level/tiled_level.hpp"

namespace gs {

TiledLevel::TiledLevel() {}

TiledLevel::TiledLevel(const std::string &tileset,
                       const std::string &json_tiled_file) {
  load(tileset, json_tiled_file);
}

void TiledLevel::load(const std::string &tileset,
                      const std::string &json_tiled_file) {
  std::ifstream my_json;
  my_json.open(json_tiled_file);
  json level = json::parse(my_json);
  my_json.close();

  tile_size = sf::Vector2u(level["tilewidth"].get<int>(),
                           level["tileheight"].get<int>());
  level_size =
      sf::Vector2u(level["width"].get<int>(), level["height"].get<int>());

  json layers = level["layers"];

  for (json::iterator it = layers.begin(); it != layers.end(); ++it) {
    if ((*it)["type"] == "tilelayer") {
      if (!(*it)["properties"].is_null() && (*it)["properties"]["collision"]) {
        TiledJsonTileLayer collision_layer(*it);
        collision_map.load(collision_layer.data, tile_size, level_size);
      } else {
        TiledJsonTileLayer tile_layer(*it);
        tile_layers.push_back(
            TileMap(tileset, tile_size, level_size, tile_layer.data));
      }
    } else if ((*it)["type"] == "objectgroup") {
      for (json::iterator it2 = (*it)["objects"].begin();
           it2 != (*it)["objects"].end(); ++it2) {
        TiledJsonObj obj(*it2, tile_size.y);
        events.insert(std::pair<std::string, TiledJsonObj>(obj.id, obj));
      }
    }
  }
}

TiledJsonObj TiledLevel::get_event(const std::string &event_id) const {
  return events.find(event_id)->second;
}

std::vector<TileMap> TiledLevel::get_tile_layers() const { return tile_layers; }

CollisionMap TiledLevel::get_collision_map() const { return collision_map; }

} // namespace gs
