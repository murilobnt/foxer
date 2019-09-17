#ifndef MY_SCENE_HPP
#define MY_SCENE_HPP

#include <SFML/Graphics.hpp>
#include <gs2d/game/level/level_proxy.hpp>
#include <gs2d/scene.hpp>

#include "character.hpp"
#include "level_one.hpp"

class MyScene : public gs::Scene {
private:
  Character character;
  gs::Camera camera;

  gs::LevelProxy l_proxy;
  sf::Vector2f delay;

public:
  void start();
  void update();
  void draw_entities();
};

#endif
