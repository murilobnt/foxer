// File: tile_grid.hpp
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

// An unity represents a cell on the tile grid. The unity contains a set of
// tiles.

struct Unity {

public:
  std::vector<Tile> tiles;
};

// A grid of tiles. Spatial Partitioning. In a game, you don't have to verify
// tiles that are way too far away from the player, because the player won't be
// colliding with them. This tile grid allows one to get tiles that are near
// the player in a grid mapping.

class TileGrid : public GenericGrid {
public:
  // Empty constructor.
  TileGrid();

  // Cosntructor. Receives the dimensions of the tile (x, y), the size of the
  // level and the desired size for an unity of the grid.
  TileGrid(sf::Vector2u tile_size, sf::Vector2u level_size, int unity_size);

  // Get the unity that a X and Y belongs.
  Unity *get_unity(int x, int y);

  // Adds a tile to the grid.
  void add_tile(Tile tile);

  // Gets the unities that intersects with the bounds of the sprite of the
  // player. If the sprite is in a zone between two or more unities, all
  // unities are returned.
  const std::vector<Unity>
  get_unities_in_position(const sf::Vector2f &sprite_upper_left,
                                const sf::FloatRect &gb) const;

private:
  // Vector of unities.
  std::vector<Unity> unities;

  // Check the boundaries of a position. If it exceeds the size of the vector,
  // (lower, as 0, or upper, as the size of the vector of unities), the values
  // are normalized.
  void check_boundaries(sf::Vector2i &before) const;

  // The size of the tiles.
  sf::Vector2u tile_size;

  // Adds a unity to the grid.
  void add_unity(std::vector<Unity> &adjacent, std::set<int> &added, int index) const;

  // Transforms a coordinate into a position of the vector of unities.
  sf::Vector2i transform_to_grid_coordinate(const sf::Vector2f &spl,
                                            int modifier_x = 0,
                                            int modifier_y = 0) const;
};

} // namespace fox

#endif
