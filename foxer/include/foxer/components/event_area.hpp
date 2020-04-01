// File: event_area.hpp
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

#ifndef FOX_EVENT_AREA_HPP_
#define FOX_EVENT_AREA_HPP_

#include <SFML/Graphics.hpp>
#include <memory>

#include "foxer/logical/tiled_json_container.hpp"
#include "foxer/abstract_components/collision_handler.hpp"

namespace fox {

class EventArea {
public:
  EventArea();
  EventArea(const TiledJsonObj &data,
            std::unique_ptr<CollisionHandler> collision_handler);
  virtual void verify_collision(const sf::FloatRect &what);

private:
  sf::FloatRect area;
  std::unique_ptr<CollisionHandler> collision_handler;
};

}

#endif
