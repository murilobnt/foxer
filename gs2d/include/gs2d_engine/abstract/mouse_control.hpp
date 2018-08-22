// File: mouse_control.hpp
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
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef MOUSE_CONTROL_HPP
#define MOUSE_CONTROL_HPP

#include <SFML/Graphics.hpp>

#include "gs2d_engine/components/sprited_entity.hpp"

// Represents an entity to have mouse controls. In this case,
// it is recommended that the entity to have mouse control
// have the information of the screen, sf::RenderWindow in
// particular to SFML, so it can define what will happen
// when the mouse clicks some point.

namespace gs {

class MouseControl {

public:
    // Defines the control for an entity by using the mouse.
    // It needs the event, the sprited entity to be manipulated
    // and the position of the mouse.
    virtual void control_entity_by_mouse(sf::Event event,
                                    SpritedEntity &sprited_entity,
                                    sf::Vector2f mouse_position) = 0;

};

}

#endif
