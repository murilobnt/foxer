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

#ifndef TILE_HPP
#define TILE_HPP

// # External
#include <SFML/Graphics.hpp>

class Tile{
private:
    // The position of the tile
    sf::Vector2f tilePosition;

    // The rect of the tile
    sf::FloatRect tileRect;

public:
    /**
    * Constructor.
    * @param tilePosition the position of the tile
    */
    Tile(sf::Vector2f tilePosition, float tileWidth, float timeHeight);

    /**
    * Get the position of the tile.
    * @return the position of the tile
    */
    sf::Vector2f getPosition() const;

    /**
    * Get the position in x axis.
    * @return the position in x axis
    */
    float getPositionX() const;

    /**
    * Get the position in y axis.
    * @return the position in y axis
    */
    float getPositionY() const;

    /**
    * Get the tile rect.
    * @return the tile rect
    */
    sf::FloatRect getTileRect() const;
    
};

#endif
