// File: game.hpp
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

#ifndef _GAME_HPP_
#define _GAME_HPP_

// # External
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>

// # Internal
#include "gamesimple/concrete/clockhandler.hpp"
#include "gamesimple/concrete/timehandler.hpp"
#include "gamesimple/concrete/scenemanager.hpp"
#include "gamesimple/abstract/scene.hpp"

class Game {

private:
  sf::RenderWindow gameScreen;

  int gameWidth;
  int gameHeight;

  ClockHandler clockHandler;
  TimeHandler gameFrequency;
  SceneManager sceneManager;

public:
  /**
   * Constructor.
   * @param gameWidth the width of the window
   * @param gameHeight the height of the window
   * @param gameTitle the title of the window
   */
  Game(int gameWidth, int gameHeight, std::string gameTitle);

  void gameStart(Scene* firstScene, bool vsync);
  void handleTimeActions();
  void processEvents();
  void clearNDraw();

  int getGameWidth() const;
  int getGameHeight() const;

  SceneManager* getSceneManager();
};

#endif
