// File: tilemap.hpp
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

#ifndef FOX_TEXTBOX_HPP_
#define FOX_TEXTBOX_HPP_

#include <SFML/Graphics.hpp>
#include "foxer/components/text.hpp"
#include "foxer/time/time_handler.hpp"

namespace fox {

class Textbox : public sf::Drawable, public sf::Transformable {
public:
  Textbox();
  Textbox(const sf::Font     &font,
          const sf::Vector2f &box_position,
          const sf::Texture  &box_texture,
          const sf::Vector2u &box_size,
          unsigned int       char_size = 30,
          float              update_rate = 120.f,
          short              margin = 25);

  TimeHandler *get_text_time_handler();
  const bool &is_active() const;

  virtual void load();
  void display_text(const std::string &what);
  void start();
  void update_text_state();
  void next();

  void setPosition(float x, float y);

private:
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  sf::VertexArray tb_va;
  sf::Texture     box_texture;
  sf::Vector2f    box_position;
  sf::Vector2u    window_size;
  sf::Vector2u    box_size;

  fox::Text       text;
  bool            active;
  float           margin;
};

}

#endif
