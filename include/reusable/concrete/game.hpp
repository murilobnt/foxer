#ifndef _GAME_HPP_
#define _GAME_HPP_

// # External
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>

// # Internal
#include "reusable/concrete/clockhandler.hpp"
#include "reusable/concrete/generictimehandler.hpp"
#include "reusable/concrete/scenemanager.hpp"
#include "reusable/interface/texturemanager.hpp"

class Game {

private:
  sf::RenderWindow gameScreen;

  int gameWidth;
  int gameHeight;

  ClockHandler clockHandler;
  GenericTimeHandler gameFrequency;
  TextureManager *textureManager;
  SceneManager sceneManager;

public:
  /**
   * Constructor.
   * @param gameWidth the width of the window
   * @param gameHeight the height of the window
   * @param gameTitle the title of the window
   */
  Game(int gameWidth, int gameHeight, std::string gameTitle);

  void gameStart(bool vsync);
  void handleTimeActions();
  void processEvents();
  void clearNDraw();

  int getGameWidth() const;
  int getGameHeight() const;
};

#endif
