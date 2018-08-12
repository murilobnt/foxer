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

#ifndef MENU_EXAMPLE_HPP
#define MENU_EXAMPLE_HPP

#include "gs2d_engine/abstract/default_scenes/simple_menu_scene.hpp"
#include "gs2d_engine/concrete/scene_changer.hpp"
#include "instance/test_scene.hpp"

class MenuExample : public SimpleMenuScene {

private:
    sf::Texture button_background_texture;
    sf::Font button_font;

    UIButton goto_test_scene;
	UIButton goto_second_scene;

public:
    MenuExample();

    void delayed_start();
    void delayed_handle_event(sf::Event event, sf::RenderWindow &screen);
};

#endif
