// File: tiled_level_data.hpp
// Author: Murilo Bento
//
// MIT License
//
// Copyright (c) 2018-2020 Murilo Bento
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef FOX_TILED_LEVEL_DATA_HPP_
#define FOX_TILED_LEVEL_DATA_HPP_

#include <map>
#include <string>
#include <vector>

#include "foxer/game/level/tiled_json_container.hpp"
#include "foxer/game/level/tilemap.hpp"
#include "foxer/other/helpers/tile_grid.hpp"

namespace fox {

// TiledLevelData store Tiled level aspects such as the tile layers, the
// collision layer and the events of a level.
// All information that one might get from are going to be a const reference.

class TiledLevelData {
public:
  // Getters.
  const std::vector<TileMap> &get_layers() const;
  const TileGrid &get_collision_tile_grid() const;
  const std::map<std::string, TiledJsonObj> &get_events() const;

  // Empty constructor.
  TiledLevelData();

  // Constructor.
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
