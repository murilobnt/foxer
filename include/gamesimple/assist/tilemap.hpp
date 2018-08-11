// File: tilemap.hpp
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

#ifndef TILEMAP_HPP
#define TILEMAP_HPP

// # External
#include <SFML/Graphics.hpp>

#include "gamesimple/assist/tilegrid.hpp"

class TileMap : public sf::Drawable, public sf::Transformable {

private:
    /**
    * Draw all tiles.
    * @param target the window to draw the tiles
    * @param states the state of the window
    */
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    // The vertices of the tiles
    sf::VertexArray m_vertices;

    // The texture of the tiles
    sf::Texture m_tileset;

    // The width of the level
    unsigned int levelWidth;

    // The height of the level
    unsigned int levelHeight;

    TileGrid tileGrid;

public:
    TileMap();

    /**
    * Load the tileset.
    * @param tileset the path to tiles' texture
    * @param tile_size the size of every tile
    * @param tiles the level represented on array
    * @param width the width of the level array
    * @param height the height of the level array
    * @param selected the selected tiles to be collided
    * @param lenght the lenght of selected array
    */
    bool load(const std::string& tileset, sf::Vector2u tile_size, const int* tiles, unsigned int width, unsigned int height);

    /**
    * Get the size of the level.
    * @return the size of the level
    */
    sf::Vector2u getLevelSize() const;

};

#endif
