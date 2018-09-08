#include "gs2d_engine/game/level/tiled_json_container.hpp"

namespace gs {

TiledJsonTileLayer::TiledJsonTileLayer(){}
TiledJsonObj::TiledJsonObj(){}

TiledJsonTileLayer::TiledJsonTileLayer(json json_obj) {
    data = json_obj["data"].get<std::vector<int>>();
}

TiledJsonObj::TiledJsonObj(json json_obj, int tile_height) {
    x = json_obj["x"].get<float>();
    y = json_obj["y"].get<float>() - tile_height;
    width = json_obj["width"].get<float>();
    height = json_obj["height"].get<float>();
    id = json_obj["name"].get<std::string>();
}

}
