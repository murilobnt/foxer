// File: rpg_level.hpp
// Author: Murilo Bento
//
// MIT License
//
// Copyright (c) 2018-2019 Murilo Bento
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

#ifndef FOX_RPG_LEVEL_HPP_
#define FOX_RPG_LEVEL_HPP_

#include <memory>
#include <vector>

#include "foxer/game/level/components/exit_area.hpp"
#include "foxer/other/geared_up/sample_level.hpp"

namespace fox {

class RPGLevel : public SampleLevel {
public:
  RPGLevel();
  explicit RPGLevel(const std::string &json);
  RPGLevel(const std::string &json, const std::string &start_position_id);

  virtual void on_fade_out();
  virtual void on_fade_in();
  virtual void handle_level_events(const float &delta_time);
  virtual void control_camera(const float &delta_time);

  void stop_player(const float &delta_time);
  void initialise_camera();
  void adjust_camera();
  void _change_level(std::shared_ptr<RPGLevel> level);

  void set_delay(sf::Vector2f *delay);
  std::shared_ptr<RPGLevel> build_level(std::shared_ptr<RPGLevel> level);

protected:
  std::vector<std::unique_ptr<ExitArea>> exit_areas;
  void add_exit_area(std::unique_ptr<ExitArea> area);

private:
  sf::Vector2f *delay;
};

}; // namespace fox

#endif
