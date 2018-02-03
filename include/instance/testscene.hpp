#ifndef _TESTSCENE_HPP_
#define _TESTSCENE_HPP_

#include <iostream>

#include "gamesimple/abstract/scene.hpp"
#include "instance/character.hpp"

class TestScene : public Scene {
private:
    Character character;
  sf::CircleShape shape;

public:
  TestScene(SceneManager *sceneManager, TextureLoader &textureLoader);
TestScene(SceneManager *sceneManager, std::string pathToImage, int w, int h,
          bool isRepeated = false, bool hasBitmask = false);

  void start();
  void update();

  void handleEvent(sf::Event event, sf::RenderWindow &screen);
  void drawEntities(sf::RenderWindow &window);

  void doInternalTimedActions();
  void resetTimeHandlers(ClockHandler &clockHandler);

  void onExit();
  void resumeScene();
};

#endif
