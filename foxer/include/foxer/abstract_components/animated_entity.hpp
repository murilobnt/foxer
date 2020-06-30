// File: animated_entity.hpp
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

#ifndef FOX_ANIMATED_ENTITY_HPP_
#define FOX_ANIMATED_ENTITY_HPP_

#include <SFML/Graphics.hpp>

#include "foxer/abstract_components/timed_entity.hpp"

// An animated entity can be used by entities that have
// a sprite and it requires an animation. In this class,
// the coder can use integers delimitors to define the position of
// the animated frames of a texture, and animate it on its own
// by implementing the abstract method animate.
// The animate method must be called in the scene of this
// entity, preferably in the doInternalTimedActions method.
// It is important that the time handler be resetted in the
// scene, so it can be sycronized with the game clock.

namespace fox {

class AnimatedEntity : public TimedEntity {
public:
  // Constructor. It takes the texture, the X and Y positions of
  // the unnanimated, and the width and height of this sprite,
  // followed up by the position of the first and the last frame of
  // the animation, in the X axis, and the position of the first and last
  // frame of the animation, in the Y axis, and then the
  // framerate of the animation.
  // The anchor of the sprite is the upper left corner.
  AnimatedEntity(float animation_framerate);

  // Empty constructor. This is important so the user of the
  // animated sprite can choose to initialize it later (but it's
  // important to not forget to do so).
  AnimatedEntity();

  // Applies the animation of the row. This means it will iterate through
  // the first frame until the last frame, and go back to the first frame
  // again in a loop.
  virtual void apply_animation_on_row(sf::Sprite *sprite,
                                      sf::Vector2i anim_x, int anim_y);

  virtual void apply_animation_on_column(sf::Sprite *sprite,
                                         int anim_x, sf::Vector2i anim_y);

  // Defines what will trigger the animation and which/how the
  // animation will happen.
  virtual void animate() = 0;

  void on_update_time();

  void set_animation_loop_state(const int &animation_loop_state);

private:
  // The integer to iterate through the animation frames. It is initialized
  // by zero (the first frame) and it is incremented when a frame is already
  // set to the sprite. When it reaches the final sprite, it is reseted to
  // zero once again.
  int animation_loop_state;
};

} // namespace fox

#endif
