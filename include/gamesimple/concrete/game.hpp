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
