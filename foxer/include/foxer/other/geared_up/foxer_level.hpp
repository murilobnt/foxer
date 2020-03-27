// File: foxer_level.hpp
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

#ifndef FOX_FOXER_LEVEL_HPP_
#define FOX_FOXER_LEVEL_HPP_

#include <memory>

#include "foxer/game/level/level.hpp"
#include "foxer/game/level/tld_loader.hpp"
#include "foxer/scene/components/object/main_object.hpp"
#include "foxer/game/level/level_bundle.hpp"
#include "foxer/game/level/level_collision_verifier.hpp"
#include "foxer/other/geared_up/default_level_col_verifier.hpp"

namespace fox {

class FoxerLevel : public Level {
public:
  FoxerLevel();
  FoxerLevel(const std::string &level_path, LevelBundle *bundle,
             std::unique_ptr<LevelCollisionVerifier> col_ver =
             std::make_unique<DefaultLevelColVerifier>());

  void set_level_bundle(LevelBundle *bundle);
  void change_level(Level *level);
  void change_level(std::shared_ptr<Level> level);

  // ===================== Inherited from Level ================================
  virtual void load();
  virtual void handle_events(const float &delta_time);
  virtual void init() = 0;
  virtual void control_camera(const float &delta_time) = 0;

  virtual void draw(sf::RenderTarget &target,
                    sf::RenderStates states) const = 0;
  // ===========================================================================
private:
  std::string level_path;

  TiledLevelData data;
  TextureHolder tex_holder;
  std::unique_ptr<LevelCollisionVerifier> col_ver;
  LevelBundle *bundle;
};

}

#endif
