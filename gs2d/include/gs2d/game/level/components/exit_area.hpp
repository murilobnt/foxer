// File: exit_area.hpp
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

#ifndef GS_EXIT_AREA_HPP
#define GS_EXIT_AREA_HPP

#include <string>

#include "gs2d/game/level/components/collidable_area.hpp"
#include "gs2d/game/level/threaded_level_loader.hpp"
#include "gs2d/other/geared_up/sample_level.hpp"
#include "gs2d/scene/components/graphic/sprited_entity.hpp"

namespace gs {

// Almost every playable level needs an exit area. This class represents an
// an area that stores a string that can be used as an access method to a
// destination area json object.

class ExitArea : public CollidableArea {
private:
  // The identifier of the destination object of the next level.
  std::string destination_id;
  ThreadedLevelLoader loader;
  std::shared_ptr<SampleLevel> next_level;

public:
  // Empty constructor.
  ExitArea();

  // Loads the exit area with the json object and the field.
  void exit_load(const gs::TiledJsonObj &exit_json,
                 std::shared_ptr<SampleLevel> next_level,
                 const std::string &field = "destination");

  // Getter.
  std::string get_destination_id() const;

  ThreadedLevelLoader *get_loader();

  virtual void verify_collision_with(SpritedEntity *entity,
                                     const float &delta_time);
  virtual void on_collision(const float &delta_time) = 0;

  void run();
};

} // namespace gs

#endif
