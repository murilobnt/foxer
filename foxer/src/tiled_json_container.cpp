#include "foxer/game/level/tiled_json_container.hpp"

namespace fox {

TiledJsonTileLayer::TiledJsonTileLayer() {}
TiledJsonObj::TiledJsonObj() {}

TiledJsonTileLayer::TiledJsonTileLayer(json json_obj) {
  data = json_obj["data"].get<std::vector<int>>();
}

TiledJsonObj::TiledJsonObj(json json_obj, int tile_height) {
  x = json_obj["x"].get<float>();
  y = json_obj["y"].get<float>() - tile_height;
  width = json_obj["width"].get<float>();
  height = json_obj["height"].get<float>();
  id = json_obj["name"].get<std::string>();

  if (!json_obj["properties"].is_null()) {
    properties = json_obj["properties"];
  }
}

} // namespace fox
