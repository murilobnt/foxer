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

#include "foxer/abstract_components/main_object.hpp"
#include "foxer/components/camera.hpp"
#include "foxer/components/textbox.hpp"
#include "foxer/components/fader.hpp"
#include "foxer/logical/level_proxy.hpp"
#include "foxer/logical/shared_texture_repository.hpp"

namespace fox {

// LevelBundle represents the data that must be shared from a level to
// another. Right now, it holds a level proxy to enable level changing from
// inside of a level, and a camera.
// It also holds a reference to the player of the level (so FoxerLevel can
// "see" it from above), and a reference to the repository of textures of the
// scene (LocalTextureRepositories need to be initialised with it).

struct LevelBundle {
  LevelProxy level_proxy;
  Camera camera;
  Fader fader;
  Textbox textbox;

  MainObject *player_ref;
  SharedTextureRepository *stex_repo;
};

} // namespace fox

#endif
