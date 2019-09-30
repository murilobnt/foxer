// File: tilemap.hpp
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

#ifndef FOX_TILEMAP_HPP_
#define FOX_TILEMAP_HPP_

// # External
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <memory>
#include <utility>
#include <vector>

#include "foxer/other/helpers/texture_holder.hpp"
#include "foxer/scene/components/camera/camera.hpp"

namespace fox {

class TileMap : public sf::Drawable, public sf::Transformable {
public:
  TileMap();

  TileMap(const std::vector<std::string> &tilesets, TextureHolder &tex_holder,
          const sf::Vector2u &tile_size, const sf::Vector2u &level_size,
          const std::vector<int> &tiles, Camera *camera);

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
  bool load(const std::vector<std::string> &tilesets, TextureHolder &tex_holder,
            const sf::Vector2u &tile_size, const sf::Vector2u &level_size,
            const std::vector<int> &tiles, Camera *camera);

private:
  /**
   * Draw all tiles.
   * @param target the window to draw the tiles
   * @param states the state of the window
   */
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  // The vertices of the tiles
  // sf::VertexArray m_vertices;

  // The texture of the tiles
  std::vector<std::pair<sf::Texture *, std::shared_ptr<sf::VertexArray>>>
      m_data;

  sf::Vector2u tile_size;
  sf::Vector2u level_size;

  Camera *camera;
};

} // namespace fox

#endif
