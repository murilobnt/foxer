#ifndef FOX_TLD_LOADER_HPP_
#define FOX_TLD_LOADER_HPP_

#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "foxer/external/json.hpp"
#include "foxer/game/level/level.hpp"
#include "foxer/game/level/tiled_json_container.hpp"
#include "foxer/game/level/tiled_level_data.hpp"
#include "foxer/game/level/tg_loader.hpp"

namespace fox::TLDLoader {

  json load_json(const std::string &path);
  std::vector<std::string> get_tilesets(const std::string &sub_path,
                                               const json &j_tilesets);
  TiledLevelData load_level(const json &level, const std::vector<std::string> &tilesets, TextureHolder &tex_holder, Camera *camera);
  TiledLevelData load(const std::string &path, TextureHolder &tex_holder, Camera *camera);

}

#endif
