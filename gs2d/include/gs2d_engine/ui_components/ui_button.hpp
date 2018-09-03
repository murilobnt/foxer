// File: ui_button.hpp
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
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef GS_UI_BUTTON_HPP
#define GS_UI_BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <string>

#include "gs2d_engine/components/sprited_entity.hpp"

namespace gs {

class UIButton : public SpritedEntity {

private:
    int id;
    bool focused;
    sf::Text button_text;

public:
    UIButton(int id, float x, float y,
             sf::Texture const& texture,
             sf::Vector2i sprite_pos_at_tex,
             sf::Vector2i sprite_dimensions,
             sf::Font& font, std::string text_content);
    UIButton();
    void set_focused(bool focused);
    bool is_focused();
    sf::Text& get_button_text();
    int get_id();
    void init_text(sf::Font& font, std::string text_content);
};

}

#endif
