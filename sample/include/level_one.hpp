// File: level_one.hpp
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

#ifndef LEVEL_ONE_HPP_
#define LEVEL_ONE_HPP_

#include <memory>
#include <string>

#include <foxer/abstract_components.hpp>
#include <foxer/components.hpp>
#include <foxer/logical/foxer_exit_area_ch.hpp>

#include "sample_exit_area_ch.hpp"
#include "character.hpp"
#include "level_two.hpp"

class LevelOne : public fox::FoxerLevel {
public:
  LevelOne();
  LevelOne(Character *player, fox::LevelBundle *bundle, fox::Fader *fader,
            const std::string start_id = "player_start_pos");

private:
  Character *player;
  fox::Fader *fader;
  fox::EventArea exit;
  std::string start_id;

  void level_update(const float &delta_time);
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  void init();
};

#endif
