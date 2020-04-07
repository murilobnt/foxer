// File: text.hpp
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

#ifndef FOX_TEXT_HPP_
#define FOX_TEXT_HPP_

#include <SFML/Graphics.hpp>
#include <queue>
#include <string>
#include <sstream>
#include <iostream>

#include "foxer/abstract_components/timed_entity.hpp"

namespace fox {

struct TextAnimationControl {
  std::string::iterator text_iterator;

  std::queue<std::string> tokenized_text;
  std::string current_word;
  sf::FloatRect text_rect;
  sf::Text copy;

  bool complete;
  bool full;

  TextAnimationControl();
  explicit TextAnimationControl(bool complete);
};

class Text : public sf::Drawable,
             public TimedEntity {
public:
  Text();
  Text(const sf::Font &font, const sf::Vector2u container_size,
       const sf::Vector2f &pos, float update_rate);
  void display_text(const std::string &what);
  void clear_text();
  void on_update_time();

  const bool &is_full() const;

private:
  void tokenize_text(const std::string &text);
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  sf::Vector2u container_size;
  sf::Text text;
  TextAnimationControl tac;
};

}

#endif
