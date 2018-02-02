#include "reusable/concrete/game.hpp"

Game::Game(int gameWidth, int gameHeight, std::string gameTitle)
    : gameScreen(sf::VideoMode(gameWidth, gameHeight), gameTitle,
                 sf::Style::Fullscreen),
      gameFrequency(sf::seconds(1.f / 60.f)) {
  this->gameWidth = gameWidth;
  this->gameHeight = gameHeight;
}

void Game::gameStart(bool vsync) {
  gameScreen.setVerticalSyncEnabled(vsync);
  while (this->gameScreen.isOpen()) {
    handleTimeActions();
    clearNDraw();

    this->clockHandler.restartClock();
    this->clockHandler.restartTimeHandler(&gameFrequency);
    sceneManager.resetTimeHandlers(clockHandler);
  }
}

void Game::handleTimeActions() {
  while (gameFrequency.timeToUpdate()) {
    processEvents();
    sceneManager.update();
    sceneManager.doInternalTimedActions();
  }
}

void Game::processEvents() {
  sf::Event event;

  while (this->gameScreen.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      gameScreen.close();
    }

    sceneManager.handleEvent(event, gameScreen);
  }
}

void Game::clearNDraw() {
  this->gameScreen.clear();
  sceneManager.drawEntities(gameScreen);
  this->gameScreen.display();
}

int Game::getGameWidth() const { return this->gameWidth; }
int Game::getGameHeight() const { return this->gameHeight; }
