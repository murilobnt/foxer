// File: simple_menu_scene.hpp
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

#ifndef GS_SIMPLE_MENU_SCENE_HPP
#define GS_SIMPLE_MENU_SCENE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "gs2d_engine/ui_components/ui_button.hpp"
#include "gs2d_engine/abstract/scene.hpp"

namespace gs {

class SimpleMenuScene : public Scene {

private:
    sf::Texture background_texture;
    sf::Sprite background;
    std::vector<sf::Text> ui_text_vec;

protected:
	std::vector<UIButton> ui_button_vec;
    std::vector<UIButton>::iterator ui_button_vec_it;

public:
    SimpleMenuScene(std::string background_texture_path,
                    int w, int h);

	void start();
    void update();
    void handle_event(sf::Event event, sf::RenderWindow &screen);

	void draw_entities(sf::RenderWindow& window);
    void add_button(UIButton& button);
    void add_text(sf::Text& text);

    virtual void delayed_start() = 0;
    virtual void delayed_handle_event(sf::Event event, sf::RenderWindow &screen) = 0;
    virtual void delayed_update();
    virtual void delayed_draw(sf::RenderWindow& window);
};

}

#endif
