// File: collision_map.hpp
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

#ifndef FOX_COLLISION_MAP_HPP_
#define FOX_COLLISION_MAP_HPP_

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

#include "foxer/other/helpers/tile.hpp"
#include "foxer/other/helpers/tile_grid.hpp"
#include "foxer/scene/components/object/game_object.hpp"

namespace fox {

// The Collision Map represents the total area of collidable entities.
// As it is now, this class stops the movement of a Game Object on collision.

class CollisionMap {
public:
  // Empty constructor.
  CollisionMap();

  // Loads the collision map. It needs a vector of integers, the size of the
  // tile and the size of the level. In the vector, 0 means no collision and
  // any number that is not 0 means that the tile is collidable.
  void load(const std::vector<int> &collision_layer_data,
            const sf::Vector2u &tile_size, const sf::Vector2u &level_size);

  // Verifies the collision of a tile to a game object. Calls handle_collision
  // if there is a collision.
  void verify_collision(GameObject &game_object);

private:
  // Stores the boolean value of a loaded map.
  bool loaded;

  // The tile grid of the collision map. This object not only stores the
  // position of every collidable tile, it also applies spatial partitioning
  // to get the tiles that are close to the game object.
  TileGrid tile_grid;

  // Handles the collision. This function stops the Game Object's movement
  // if the next one will make him collide with something.
  virtual void handle_collision(GameObject &game_object,
                                const sf::FloatRect &gb,
                                const sf::FloatRect &tile_rect,
                                const sf::Vector2f &movement);
};

} // namespace fox

#endif
