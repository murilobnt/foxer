// File: scene.hpp
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

#ifndef _SCENE_HPP_
#define _SCENE_HPP_

#include <SFML/Graphics.hpp>

#include "gamesimple/concrete/clockhandler.hpp"
#include "gamesimple/concrete/scenemanager.hpp"
#include "gamesimple/concrete/textureloader.hpp"

// Scenes serves as the mold for any scene, e.g. the main menu
// and the pause screen. It contains methods for loading resources,
// updating the scene, event handling, entities drawing, timed actions
// events handling, time handlers reset, if necessary, and methods to
// define what the scene will do once it the user have exited it
// and once the user have resumed it.
// Every virtual method of this class is called by the game class
// which uses a scene manager to do the calls

class Scene {
protected:
  // The reference to the scene manager of the game. It is important for
  // the coder can change the current scene for another one inside the
  // scene.
  SceneManager *sceneManager;

  // A texture loader to help the user on loading any texture. Better used
  // in the start function.
  TextureLoader textureLoader;

public:
  // Constructor. Sets the scene manager for the scene.
  Scene(SceneManager *sceneManager);

  // Empty constructor. Important for delaying the SceneManager
  // pointer initialization.
  Scene();

  // Virtual destructor. This means allocated memory with the new
  // operator can be freed on the child scene.
  virtual ~Scene();

  // Resources loading, like creating textures and setting sprites position.
  virtual void start() = 0;

  // Updating phase. The method to implement this function will be called every
  // tick. e.g. a platform game where you constantly need to check if the player
  // have been hit by an enemy.
  virtual void update() = 0;

  // The method to implement this function will tell how an received event will
  // be handled. Using the ControlableEntity class is strongly recommended.
  virtual void handleEvent(sf::Event event, sf::RenderWindow &screen) = 0;

  // Drawing phase. The method to implement this will be responsible
  // to draw every drawable entity of the scene,
  virtual void drawEntities(sf::RenderWindow &window) = 0;

  // This will define actions that occur in different rates than the update.
  // e.g. the animation of a sprite that has a framerate of 20
  // can be called inside here.
  virtual void doInternalTimedActions() = 0;

  // This shall be implemented to reset all the time handlers used
  // in the scene, so they can be sycronized to the clock of the
  // entire application.
  virtual void resetTimeHandlers(ClockHandler &clockHandler) = 0;

  // This will define what will happen once the user have exited
  // the scene.
  virtual void onExit() = 0;

  // This will define what will happen once the user have resumed
  // the scene.
  virtual void resumeScene() = 0;

  // This will change the current scene for another one.
  // The new scene is passed through the parameter, and it is
  // set into the scene manager, and used by the game.
  void changeScene(Scene *nextScene);

  // Will set a new scene manager to the scene.
  void setSceneManager(SceneManager *sceneManager);

  // Returns the scene manager of the scene.
  SceneManager *getSceneManager();
};

#endif
