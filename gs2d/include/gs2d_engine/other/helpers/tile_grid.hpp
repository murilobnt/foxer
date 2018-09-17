// File: tile_grid.hpp
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
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef GS_TILE_GRID_HPP
#define GS_TILE_GRID_HPP

// # External
#include <vector>
#include <cmath>
#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>

// # Internal
#include "gs2d_engine/other/helpers/tile.hpp"
#include "gs2d_engine/other/helpers/generic_grid.hpp"

struct Unity {

public:
    std::vector<gs::Tile> tiles;

};

namespace gs {

class TileGrid : public GenericGrid {

private:
    std::vector<Unity> unities;
    void check_boundaries(sf::Vector2i &before);
    sf::Vector2u tile_size;

public:
    TileGrid();

    TileGrid(sf::Vector2u tile_size, sf::Vector2u level_size, int unity_size);

    Unity* get_unity(int x, int y);

    void add_tile(Tile tile);

    std::vector<Unity> get_unities_in_position(const sf::Vector2f &sprite_upper_left);

};

}

#endif
