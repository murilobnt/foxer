#ifndef _TESTSCENE_HPP_
#define _TESTSCENE_HPP_

#include <iostream>

#include "gamesimple/abstract/scene.hpp"
#include "gamesimple/components/spritedentity.hpp"
#include "instance/character.hpp"

class TestScene : public Scene {
private:
  sf::Texture charTexture;
  sf::Texture bgTexture;

  Character character;
  SpritedEntity bg;

public:
  TestScene(SceneManager *sceneManager);

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
