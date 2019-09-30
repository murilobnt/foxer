// File: main_object.hpp
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

#ifndef FOX_MAIN_OBJECT_HPP_
#define FOX_MAIN_OBJECT_HPP_

#include "foxer/scene/components/control/ib_controlable_entity.hpp"
#include "foxer/scene/components/graphic/animated_entity.hpp"
#include "foxer/scene/components/object/game_object.hpp"

namespace fox {

class MainObject : public IBControlableEntity,
                   public GameObject,
                   public AnimatedEntity {

public:
  MainObject();
  MainObject(sf::Texture const &texture, float animation_framerate,
             sf::Vector2i sprite_dimensions,
             sf::Vector2i sprite_pos_at_tex = sf::Vector2i(0, 0));
};

} // namespace fox

#endif
