// File: tile_grid.hpp
// Author: Murilo Bento
//
// MIT License
//
// Copyright (c) 2018-2019 Murilo Bento
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

#ifndef FOX_TILE_GRID_HPP_
#define FOX_TILE_GRID_HPP_

// # External
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>

// # Internal
#include "foxer/other/helpers/generic_grid.hpp"
#include "foxer/other/helpers/tile.hpp"

namespace fox {

struct Unity {

public:
  std::vector<Tile> tiles;
};

class TileGrid : public GenericGrid {
public:
  TileGrid();

  TileGrid(sf::Vector2u tile_size, sf::Vector2u level_size, int unity_size);

  Unity *get_unity(int x, int y);

  void add_tile(Tile tile);

  std::vector<Unity>
  get_unities_in_position(const sf::Vector2f &sprite_upper_left,
                          const sf::FloatRect &gb);

private:
  std::vector<Unity> unities;
  void check_boundaries(sf::Vector2i &before);
  sf::Vector2u tile_size;
  void add_unity(std::vector<Unity> &adjacent, std::set<int> &added, int index);
  sf::Vector2i transform_to_grid_coordinate(const sf::Vector2f &spl,
                                            int modifier_x = 0,
                                            int modifier_y = 0);
};

} // namespace fox

#endif
