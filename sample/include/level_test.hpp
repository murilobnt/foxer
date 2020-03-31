// File: level_test.hpp
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

#ifndef LEVEL_TEST_HPP_
#define LEVEL_TEST_HPP_

#include <foxer/abstract_components.hpp>

#include "character.hpp"

class LevelTest : public fox::FoxerLevel {
public:
  LevelTest();
  LevelTest(Character *player, fox::LevelBundle *bundle);


private:
  Character *player;
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  void init();
  void control_camera(const float &delta_time);
};

#endif
