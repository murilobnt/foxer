// File: sample_level.hpp
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

#ifndef FOX_SAMPLE_LEVEL_HPP_
#define FOX_SAMPLE_LEVEL_HPP_

#include "foxer/game/level/threaded_level_loader.hpp"
#include "foxer/game/level/tiled_level.hpp"
#include "foxer/other/helpers/fader.hpp"
#include "foxer/scene/components/object/main_object.hpp"

namespace fox {

class SampleLevel : public TiledLevel {
public:
  SampleLevel();
  SampleLevel(const std::string &json_level);
  SampleLevel(const std::string &json_level,
              const std::string &start_position_id);

  void init();
  void handle_events(const float &delta_time);
  void set_start_position_id(const std::string &start_position_id);
  void set_player(MainObject *player);

protected:
  int fading_speed;
  MainObject *player;

  std::string start_position_id;

  ThreadedLevelLoader *loader;
  Fader fader;

  virtual void handle_game_events(const float &delta_time);
  virtual void handle_fade(const FadeState &fade_state);

  virtual void on_fade_out() = 0;
  virtual void on_fade_in() = 0;
  virtual void handle_level_events(const float &delta_time) = 0;
  virtual void level_init() = 0;
};

} // namespace fox

#endif
