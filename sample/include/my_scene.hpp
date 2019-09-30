#ifndef MY_SCENE_HPP
#define MY_SCENE_HPP

#include <SFML/Graphics.hpp>
#include <foxer/game/level/level_proxy.hpp>
#include <foxer/scene.hpp>

#include "character.hpp"
#include "level_one.hpp"

class MyScene : public fox::Scene {
private:
  Character character;
  sf::Vector2f delay;

public:
  void start();
  void update();
  void draw_entities();
};

#endif
