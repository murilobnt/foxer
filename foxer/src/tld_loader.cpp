#include "foxer/logical/tld_loader.hpp"

namespace fox::TLDLoader {

  json load_json(const std::string &path){
    std::ifstream my_json;
    my_json.open(path);
    json result = json::parse(my_json);
    my_json.close();
    return result;
  }

  std::vector<std::string> get_tilesets(const std::string &sub_path,
                                        json &j_tilesets) {
    std::vector<std::string> tilesets;
    for (auto it = j_tilesets.begin(); it != j_tilesets.end(); ++it) {
      std::string source = sub_path + "/" + (*it)["source"].get<std::string>();
      json tileset = load_json(source);
      std::string img_path = source.substr(0, source.find_last_of('/')) + "/" +
                             tileset["image"].get<std::string>();

      tilesets.push_back(img_path);
    }

    return tilesets;
  }

  TiledLevelData load_level(json &level, const std::vector<std::string> &tilesets, LocalTextureRepository &ltex_repo, Camera *camera){
    sf::Vector2u tile_size(level["tilewidth"].get<int>(), level["tileheight"].get<int>());
    sf::Vector2u level_size(level["width"].get<int>(), level["height"].get<int>());

    json j_layers = level["layers"];
    std::vector<TileMap> layers;
    TileGrid collision_tile_grid;
    std::map<std::string, TiledJsonObj> events;

    for (auto it = j_layers.begin(); it != j_layers.end(); ++it) {
      if ((*it)["type"] == "tilelayer") {
        bool collision_layer = false;
        if(!(*it)["properties"].is_null()){
          for (auto it2 = (*it)["properties"].begin(); it2 != (*it)["properties"].end(); ++it2) {
            if((*it2)["name"] == "collision" && (*it2)["value"]){
              collision_tile_grid = TGLoader::load((*it)["data"].get<std::vector<int>>(), tile_size, level_size);
              collision_layer = true;
            }
          }
        }

        if(!collision_layer)
          layers.push_back(TileMap(tilesets, ltex_repo, tile_size, level_size, (*it)["data"].get<std::vector<int>>(), camera));

      } else if ((*it)["type"] == "objectgroup") {
        for (auto it2 = (*it)["objects"].begin();
             it2 != (*it)["objects"].end(); ++it2) {
          TiledJsonObj obj(*it2, tile_size.y);
          events.insert(std::pair<std::string, TiledJsonObj>(obj.id, obj));
        }
      }
    }

    TiledLevelData data(tile_size, level_size, layers, collision_tile_grid, events);
    return data;
  }

  TiledLevelData load(const std::string &path, LocalTextureRepository &ltex_repo, Camera *camera){
    json level = load_json(path);
    return load_level(level, get_tilesets(path.substr(0, path.find_last_of('/')), level["tilesets"]), ltex_repo, camera);
  }

}
