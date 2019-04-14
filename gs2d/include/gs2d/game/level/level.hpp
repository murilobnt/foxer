// File: level.hpp
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

#include <SFML/Graphics.hpp>
#include <vector>

#include "gs2d/game/level/collision_map.hpp"
#include "gs2d/game/level/tilemap.hpp"

#ifndef GS_LEVEL_HPP
#define GS_LEVEL_HPP

#include "gs2d/game/level/layer_container.hpp"

namespace gs {

class Level : public sf::Drawable {
protected:
  sf::Vector2u tile_size;
  sf::Vector2u level_size;

  std::vector<TileMap> layers;
  CollisionMap collision_map;

  TileMap get_layer(int index) const;
  LayerContainer get_layers(int from, int to) const;

  virtual void draw(sf::RenderTarget &target,
                    sf::RenderStates states) const = 0;

public:
  virtual void load() = 0;
  virtual void handle_events() = 0;
};

} // namespace gs

#endif
