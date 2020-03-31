// File: ib_controlable_entity.hpp
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

#ifndef FOX_IB_CONTROLABLE_ENTITY_HPP_
#define FOX_IB_CONTROLABLE_ENTITY_HPP_

#include <SFML/Graphics.hpp>

// Represents an input based controlable entity. The entity will have to respond
// to when a key of the keyboard is pressed or not, and the
// method control_entity will be responsible for doing so.
// e.g.:
//     class Car : public IBControlableEntity {
//         void control_entity(){
//           if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
//             this->moveUp();
//         }
//     }

namespace fox {

class IBControlableEntity {

public:
  // Defines how the entity will respond to any input.
  virtual void control_entity(float delta_time) = 0;
};

} // namespace fox

#endif
