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
#include "foxer/abstract_components/timed_entity.hpp"

namespace fox {

enum FadeState {
  COMPLETE,
  FADE_IN,
  FADE_OUT
};

class Fader : public sf::Sprite, public TimedEntity {
public:
  Fader();
  Fader(const sf::RenderTexture *rt, const sf::Time &update_rate);

  void fade_out();
  void fade_in();

  void on_update_time();
  bool is_complete();

private:
  int alpha;
  FadeState state;
};

}

#endif
