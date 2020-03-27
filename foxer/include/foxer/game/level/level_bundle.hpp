// File: level_bundle.hpp
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

#ifndef FOX_LEVEL_BUNDLE_HPP_
#define FOX_LEVEL_BUNDLE_HPP_

#include "foxer/game/level/level_proxy.hpp"
#include "foxer/other/helpers/shared_texture_holder.hpp"
#include "foxer/scene/components/camera/camera.hpp"
#include "foxer/scene/components/object/main_object.hpp"

namespace fox {

struct LevelBundle {
  LevelProxy level_proxy;
  SharedTextureHolder shared_t_holder;
  Camera camera;

  MainObject *player_ref;
  
  LevelBundle();
  LevelBundle(MainObject *player_ref, const sf::Vector2f &cam_viewport_size);
};

} // namespace fox

#endif
