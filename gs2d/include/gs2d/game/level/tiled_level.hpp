// File: tiled_level.hpp
// Author: Murilo Bento
//
// MIT License
//
// Copyright (c) 2018 Murilo Bento
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

#ifndef GS_TILED_LEVEL_HPP
#define GS_TILED_LEVEL_HPP

#include <SFML/Graphics.hpp>
#include <fstream>
#include <map>
#include <queue>
#include <string>
#include <vector>

#include "gs2d/external/json.hpp"
#include "gs2d/game/level/collision_map.hpp"
#include "gs2d/game/level/tiled_json_container.hpp"
#include "gs2d/game/level/tilemap.hpp"

namespace gs {

class TiledLevel : public sf::Drawable {
private:
  sf::Vector2u tile_size;
  sf::Vector2u level_size;

  std::vector<TileMap> tile_layers;
  CollisionMap collision_map;
  std::map<std::string, TiledJsonObj> events;

  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
  TiledLevel();
  TiledLevel(const std::vector<std::string> &tilesets,
             const std::string &json_tiled_file);

  void load(const std::vector<std::string> &tilesets,
            const std::string &json_tiled_file);
  std::vector<TileMap> get_tile_layers() const;
  CollisionMap get_collision_map() const;
  TiledJsonObj get_event(const std::string &event_id) const;
};

} // namespace gs

#endif
