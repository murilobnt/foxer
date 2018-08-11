#include "gamesimple/concrete/game.hpp"

Game::Game(int gameWidth, int gameHeight,
           std::string gameTitle, float framerate)
        : gameScreen(sf::VideoMode(gameWidth, gameHeight), gameTitle),
        gameFrequency(sf::seconds(1.f / framerate)) {
        this->gameWidth = gameWidth;
        this->gameHeight = gameHeight;
}

void Game::gameStart(Scene *firstScene, bool vsync) {
        gameScreen.setVerticalSyncEnabled(vsync);
        firstScene->setSceneManager(getSceneManager());
        sceneManager.setScene(firstScene);

        while (gameScreen.isOpen()) {
                handleTimeActions();
                clearAndDraw();

                clockHandler.restartClock();
                clockHandler.restartTimeHandler(&gameFrequency);
                sceneManager.resetTimeHandlers(clockHandler);
        }
}

void Game::handleTimeActions() {
        while (gameFrequency.timeToUpdate()) {
                processEvents();
                sceneManager.update();
        }
}

void Game::processEvents() {
        sf::Event event;

        while (gameScreen.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                        gameScreen.close();
                }

                sceneManager.handleEvent(event, gameScreen);
        }
}

void Game::clearAndDraw() {
        gameScreen.clear();
        sceneManager.drawEntities(gameScreen);
        gameScreen.display();
}

int Game::getGameWidth() const {
        return gameWidth;
}

int Game::getGameHeight() const {
        return gameHeight;
}

SceneManager *Game::getSceneManager() {
        return &sceneManager;
}
