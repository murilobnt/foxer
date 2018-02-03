#ifndef _SCENE_HPP_
#define _SCENE_HPP_

#include <SFML/Graphics.hpp>

#include "gamesimple/concrete/clockhandler.hpp"
#include "gamesimple/concrete/scenemanager.hpp"
#include "gamesimple/concrete/textureloader.hpp"

class Scene {
protected:
  SceneManager *sceneManager;
  TextureLoader textureLoader;

public:
  Scene(SceneManager *sceneManager);

  virtual void start() = 0;
  virtual void update() = 0;

  virtual void handleEvent(sf::Event event, sf::RenderWindow &screen) = 0;
  virtual void drawEntities(sf::RenderWindow &window) = 0;

  virtual void doInternalTimedActions() = 0;
  virtual void resetTimeHandlers(ClockHandler &clockHandler) = 0;

  virtual void onExit() = 0;
  virtual void resumeScene() = 0;

  void changeScene(Scene *nextScene);

  void setSceneManager(SceneManager *sceneManager);
  SceneManager *getSceneManager();
};

#endif
