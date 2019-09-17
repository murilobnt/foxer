// File: sample_level.hpp
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

#ifndef SAMPLE_LEVEL_HPP
#define SAMPLE_LEVEL_HPP

#include "gs2d/game/level/threaded_level_loader.hpp"
#include "gs2d/game/level/tiled_level.hpp"
#include "gs2d/other/helpers/fader.hpp"
#include "gs2d/scene/components/object/main_object.hpp"

namespace gs {

class SampleLevel : public gs::TiledLevel {
private:
  bool fade_in;

  void handle_game_events(const float &delta_time);
  void handle_fade(const gs::FadeState &fade_state);

protected:
  int fading_speed;
  gs::MainObject *character;
  std::string start_position_id;

  gs::ThreadedLevelLoader *loader;
  gs::Fader fader;

  virtual void on_fade_out() = 0;
  virtual void on_fade_in() = 0;
  virtual void handle_level_events(const float &delta_time) = 0;
  virtual void level_init() = 0;

public:
  SampleLevel();
  SampleLevel(SharedTextureHolder *shared_holder, gs::LevelProxy *level_proxy,
              gs::MainObject *character, Camera *camera,
              const std::string &json_level,
              const std::string &start_position_id, bool load = false,
              bool fade_in = true);

  void init();
  void handle_events(const float &delta_time);
};

} // namespace gs

#endif
