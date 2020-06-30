// File: level.hpp
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

#ifndef FOX_LEVEL_HPP_
#define FOX_LEVEL_HPP_

#include <SFML/Graphics.hpp>

namespace fox {

// This class represents a level. Its purpose is to prevent the coder
// to create a scene for every existent level of a game.

class Level : public sf::Drawable {
public:
  // Resources loading.
  virtual void load() = 0;

  // Initial settings of the level (called once the level is changed).
  virtual void init() = 0;

  // Handle events that happen every tick, like moving the player.
  virtual void level_update(const float &delta_time) = 0;

  // virtual void handle_event(const sf::Event &event) = 0;

  // Controls the camera. Placed after level_update is executed.
  virtual void control_camera(const float &delta_time) = 0;

  // ======================= Inherited from sf::Drawable =======================
  virtual void draw(sf::RenderTarget &target,
                    sf::RenderStates states) const = 0;
  // ===========================================================================
};

} // namespace fox

#endif
