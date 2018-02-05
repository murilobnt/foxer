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

#ifndef GAME_HPP
#define GAME_HPP

// # External
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>

// # Internal
#include "gamesimple/concrete/clockhandler.hpp"
#include "gamesimple/concrete/timehandler.hpp"
#include "gamesimple/concrete/scenemanager.hpp"
#include "gamesimple/abstract/scene.hpp"

// The entity that maintains the game cycle. It is responsable for
// delegating actions for its scene managers, which repasses it
// to its current scene. It also keeps the game to the framerate.

class Game {

private:
  // The window of the application.
  sf::RenderWindow gameScreen;

  // The width and the height of the game window.
  int gameWidth;
  int gameHeight;

  // The clock of the game.
  ClockHandler clockHandler;

  // The timehandler to define the framerate of the game.
  TimeHandler gameFrequency;

  // The scene manager to delegate actions for the scene.
  SceneManager sceneManager;

public:
  // Constructor. Requires the width and height of the game window and its
  // title too.
  Game(int gameWidth, int gameHeight, std::string gameTitle, float frameratePerSecond = 60.f);

  // Start the game. This begins the game cycle, verifying if the
  // window is still open to do the operations. It requires the first
  // scene to be played and the bool to use vsync.
  void gameStart(Scene* firstScene, bool vsync = true);

  // This will handle the actions inside the framerate.
  void handleTimeActions();

  // This will process the events.
  void processEvents();

  // This will clear the screen, draw and display the entities of
  // the current scene. It calls for the drawEntities method from the
  // scene.
  void clearNDraw();

  // Getters for the game width and height.
  int getGameWidth() const;
  int getGameHeight() const;

  // Getter for the scene manager.
  SceneManager* getSceneManager();
};

#endif
