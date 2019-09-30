// File: tile.hpp
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

#ifndef FOX_TILE_HPP
#define FOX_TILE_HPP

// # External
#include <SFML/Graphics.hpp>

#include <iostream>

namespace fox {

class Tile {
private:
  // The position of the tile
  sf::Vector2f tile_position;

  // The rect of the tile
  sf::FloatRect tile_rect;

public:
  /**
   * Constructor.
   * @param tile_position the position of the tile
   */
  Tile(const sf::Vector2f &tile_position, const sf::Vector2u &tile_size);

  /**
   * Get the position of the tile.
   * @return the position of the tile
   */
  sf::Vector2f get_position() const;

  /**
   * Get the position in x axis.
   * @return the position in x axis
   */
  float get_position_x() const;

  /**
   * Get the position in y axis.
   * @return the position in y axis
   */
  float get_position_y() const;

  /**
   * Get the tile rect.
   * @return the tile rect
   */
  sf::FloatRect get_tile_rect() const;
};

} // namespace fox

#endif
