// File: sprited_entity.hpp
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

#ifndef FOX_CAMERA_HPP
#define FOX_CAMERA_HPP

#include <SFML/Graphics.hpp>

namespace fox {

class Camera {
private:
  sf::View view;

public:
  Camera(sf::Vector2f const camera_center_position,
         sf::Vector2f const camera_dimensions);

  Camera(sf::Vector2f const camera_center_position,
         sf::Vector2f const camera_dimensions, float const zoom);

  explicit Camera(sf::Vector2f const camera_dimensions);
  Camera(sf::Vector2f const camera_dimensions, float const zoom);

  Camera();

  void apply_zoom(float const zoom);
  void center_at_sprite(const sf::Sprite &sprite);
  void center_at_sprite(const sf::Sprite &sprite,
                        const sf::Vector2u &level_size);
  void center_at_position(sf::Vector2f position);
  sf::Vector2f get_center() const;
  sf::View get_view() const;
  sf::Vector2f get_size() const;
  void move(sf::Vector2f movement);
};

} // namespace fox

#endif
