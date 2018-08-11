// File: animatedentity.hpp
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

#ifndef ANIMATEDENTITY_HPP
#define ANIMATEDENTITY_HPP

#include "gamesimple/components/spritedentity.hpp"
#include "gamesimple/concrete/timehandler.hpp"

// An animated entity can be used by entities that have
// a sprite and it requires an animation. In this class,
// the coder can use integers delimitors to define the position of
// the animated frames of a texture, and animate it on its own
// by implementing the abstract method animate.
// The animate method must be called in the scene of this
// entity, preferably in the doInternalTimedActions method.
// It is important that the time handler be resetted in the
// scene, so it can be sycronized with the game clock.

class AnimatedEntity : public SpritedEntity {
private:
  // The X position of the first frame of the animated sprite.
  // e.g. if the first frame is located in the left corner of the image,
  // this field would have to have the value of 0.
  // It will be used to iterate through the animation.
  // The anchor of the sprite is the upper left corner.
  int animationInitialXPosition;

  // The X position of the last frame of the animated sprite.
  // e.g. if the last frame of the animation is located at the end
  // of the image, with the image being 192x128 and the sprite
  // size is 32x32px, this field would have to have the value of
  // 192 - 32, which is 160.
  // The anchor of the sprite is the upper left corner.
  int animationFinalXPosition;

  // The Y position of the first frame of the animated sprite.
  // This field will be used to iterate through the rows
  // of the animation. By rows, it is this initial position
  // plus the height of the sprite.
  // The anchor of the sprite is the upper left corner.
  int animationInitialYPosition;

  // The Y position of the last frame in the Y position.
  // This field can be used if the animmation is set on a column
  // insted of a row, so we can loop through the animation
  // with this information.
  // The anchor of the sprite is the upper left corner.
  int animationFinalYPosition;

  // A time handler to define the animation framerate. It is important
  // to reset this time handler in the scene of this sprite, so
  // it can be syncronized with the game's clock.
  TimeHandler animationTimeHandler;

  // The integer to iterate through the animation frames. It is initialized
  // by zero (the first frame) and it is incremented when a frame is already
  // set to the sprite. When it reaches the final sprite, it is resetted to
  // zero once again.
  int animationLoopState;

public:
  // Constructor. It takes the texture, the X and Y positions of
  // the unnanimated, and the width and height of this sprite,
  // followed up by the position of the first and the last frame of
  // the animation, in the X axis, and the position of the first and last
  // frame of the animation, in the Y axis, and then specifying the
  // framerate of the animation.
  // The anchor of the sprite is the upper left corner.
  AnimatedEntity(sf::Texture const &texture, int spriteX, int spriteY,
                 int spriteW, int spriteH, int animationInitialXPosition,
                 int animationFinalXPosition, int animationInitialYPosition,
                 int animationFinalYPosition, float animationFramesPerSecond);

  // Empty constructor. This is important so the user of the
  // animated sprite can choose to initialize it later (but it's
  // important to not forget to do so).
  AnimatedEntity();

  // Getter for the X position of the first frame of the animated sprite.
  int getAnimationInitialXPosition() const;

  // Getter for the X position of the last frame of the animated sprite.
  int getAnimationFinalXPosition() const;

  // Getter for the Y position of the first frame of the animated sprite.
  int getAnimationInitialYPosition() const;

  // Getter for the Y position of the last frame in the Y position.
  int getAnimationFinalYPosition() const;

  // Getter for the time handler of the animation.
  TimeHandler &getAnimationTimeHandler();

  // Applies the animation of the row. This means it will iterate through
  // the first frame until the last frame, and go back to the first frame
  // again in a loop.
  void applyAnimation(int row);

  // Defines what will trigger the animation and which/how the
  // animation will happen.
  virtual void animate() = 0;
};

#endif
