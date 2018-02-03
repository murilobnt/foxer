#ifndef _SCENE_HPP_
#define _SCENE_HPP_

#include <SFML/Graphics.hpp>

#include "gamesimple/concrete/clockhandler.hpp"
#include "gamesimple/concrete/scenemanager.hpp"
#include "gamesimple/concrete/textureloader.hpp"

// Control camera vai estar no update se for necessário :D

class Scene {
protected:
  SceneManager *sceneManager;
  TextureLoader textureLoader;

public:
  Scene(SceneManager *sceneManager);
  Scene(SceneManager *sceneManager, TextureLoader &textureLoader);
  Scene(SceneManager *sceneManager, std::string pathToImage, int w, int h,
                           bool isRepeated = false, bool hasBitmask = false);

  virtual void start() = 0;
  virtual void update() = 0;

  virtual void handleEvent(sf::Event event, sf::RenderWindow &screen) = 0;
  virtual void drawEntities(sf::RenderWindow &window) = 0;

  virtual void doInternalTimedActions() = 0;
  virtual void resetTimeHandlers(ClockHandler &clockHandler) = 0;

  virtual void onExit() = 0;
  virtual void resumeScene() = 0;

  void changeScene(Scene *nextScene);
  void setTextureLoader(TextureLoader &textureLoader);
  void createTextureLoader(std::string pathToImage, int w, int h,
                           bool isRepeated = false, bool hasBitmask = false);

  void setSceneManager(SceneManager *sceneManager);
  SceneManager *getSceneManager();
};

#endif
