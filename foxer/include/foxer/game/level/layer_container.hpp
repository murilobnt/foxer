// File: layer_container.hpp
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

#ifndef FOX_LAYER_CONTAINER_HPP
#define FOX_LAYER_CONTAINER_HPP

#include <vector>

#include "foxer/game/level/tilemap.hpp"

namespace fox {

// This class represents a container for layers of TileMaps.

class LayerContainer : public sf::Drawable {
private:
  // The layers of tiles.
  std::vector<TileMap> tile_layers;

  // The draw method.
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
  // Constructor. It takes a vector of TileMaps.
  explicit LayerContainer(std::vector<TileMap> tile_layers);
};

} // namespace fox

#endif
