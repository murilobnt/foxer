// File: collision_map.hpp
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

#ifndef GS_COLLISION_MAP_HPP
#define GS_COLLISION_MAP_HPP

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

#include "gs2d/other/helpers/tile.hpp"
#include "gs2d/other/helpers/tile_grid.hpp"
#include "gs2d/scene/components/object/game_object.hpp"

namespace gs {

class CollisionMap {
private:
  bool loaded;
  TileGrid tile_grid;
  void handle_collision(GameObject &game_object, const sf::FloatRect &gb,
                        const sf::FloatRect &tile_rect,
                        const sf::Vector2f &movement);

public:
  CollisionMap();

  void load(const std::vector<int> &collision_layer_data,
            const sf::Vector2u &tile_size, const sf::Vector2u &level_size);

  void verify_collision(GameObject &game_object);
};

} // namespace gs

#endif
