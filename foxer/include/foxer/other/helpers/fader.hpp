// File: fader.hpp
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

#ifndef FOX_FADER_HPP_
#define FOX_FADER_HPP_

#include <SFML/Graphics.hpp>

#include "foxer/other/geared_up/fade_state.hpp"

namespace fox {

class Fader : public sf::Drawable {
public:
  Fader();
  explicit Fader(sf::Vector2f size);
  Fader(sf::Vector2f size, sf::Vector2f position);

  bool fade_in(short speed);
  bool fade_out(short speed);

  void start_fade_in();
  void start_fade_out();

  FadeState get_fade_state() const;

private:
  sf::RectangleShape fader;
  short alpha;
  FadeState fade_state;
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

} // namespace fox

#endif
