#include "gs2d/game/level/tiled_level.hpp"

namespace gs {

TiledLevel::TiledLevel() {}

TiledLevel::TiledLevel(const std::string &json_tiled_file) {
  load(json_tiled_file);
}

std::vector<std::string> TiledLevel::get_tilesets(const std::string &sub_path,
                                                  json j_tilesets) {
  std::vector<std::string> tilesets;
  for (json::iterator it = j_tilesets.begin(); it != j_tilesets.end(); ++it) {
    std::string source = sub_path + "/" + (*it)["source"].get<std::string>();

    std::ifstream my_json;
    my_json.open(source);
    json tileset = json::parse(my_json);
    my_json.close();

    std::string img_path = source.substr(0, source.find_last_of('/')) + "/" +
                           tileset["image"].get<std::string>();

    tilesets.push_back(img_path);
  }
  return tilesets;
}

void TiledLevel::load(const std::string &json_tiled_file) {
  std::ifstream my_json;
  my_json.open(json_tiled_file);
  json level = json::parse(my_json);
  my_json.close();

  std::vector<std::string> tilesets =
      get_tilesets(json_tiled_file.substr(0, json_tiled_file.find_last_of('/')),
                   level["tilesets"]);

  tile_size = sf::Vector2u(level["tilewidth"].get<int>(),
                           level["tileheight"].get<int>());
  level_size =
      sf::Vector2u(level["width"].get<int>(), level["height"].get<int>());

  json layers = level["layers"];

  for (json::iterator it = layers.begin(); it != layers.end(); ++it) {
    if ((*it)["type"] == "group") {
      bool overlay = !(*it)["properties"]["overlay"].is_null() &&
                     (*it)["properties"]["overlay"];

      for (json::iterator g_it = (*it)["layers"].begin();
           g_it != (*it)["layers"].end(); ++g_it) {
        TileMap tilemap(tilesets, tile_size, level_size,
                        TiledJsonTileLayer(*g_it).data);
        (overlay ? overlay_layers.add_layer(tilemap)
                 : lower_layers.add_layer(tilemap));
      }
    } else if ((*it)["type"] == "tilelayer" &&
               !(*it)["properties"]["collision"].is_null() &&
               (*it)["properties"]["collision"]) {
      TiledJsonTileLayer collision_layer(*it);
      collision_map.load(collision_layer.data, tile_size, level_size);
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

CollisionMap TiledLevel::get_collision_map() const { return collision_map; }

std::map<std::string, TiledJsonObj> TiledLevel::get_events() const {
  return events;
}

TiledLayerContainer TiledLevel::get_lower_layers() const {
  return lower_layers;
}

TiledLayerContainer TiledLevel::get_overlay_layers() const {
  return overlay_layers;
}

} // namespace gs
