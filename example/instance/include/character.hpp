// File: character.hpp
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

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

#include "gs2d_engine/scene_components.hpp"
#include "gs2d_engine/time.hpp"
#include "facing_position.hpp"

class Character : public gs::AnimatedEntity, public gs::IBControlableEntity {

private:
    sf::Vector2f movement;
    gs::TimeHandler animation_time_handler;

    bool moving_up;
    bool moving_down;
    bool moving_left;
    bool moving_right;

    FacingPosition current_facing_pos;
    FacingPosition last_facing_pos;

public:
    Character(sf::Texture const &texture, sf::Vector2i sprite_pos_at_tex,
              sf::Vector2i sprite_dimensions, sf::Vector2i animation_x,
              sf::Vector2i animation_y, int animation_framerate);
    Character();
    void control_entity();
    void move_character();
    void animate();

};

#endif
