// File: test_scene.hpp
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

#ifndef TEST_SCENE_HPP
#define TEST_SCENE_HPP

#include <iostream>

#include "gs2d_engine/scene.hpp"
#include "gs2d_engine/other/helpers/tilemap.hpp"

#include "character.hpp"
#include "second_scene.hpp"

class MenuExample;

class TestScene : public gs::Scene {

private:
    gs::Camera camera;
    gs::TileMap test_tm;

    sf::Texture char_texture;

    Character character;

    void timed_events();

public:
    ~TestScene();

    void start();
    void update();

    void handle_event(sf::Event &event);
    void draw_entities();

    void on_exit();

};

#endif
