#ifndef MY_SCENE_HPP
#define MY_SCENE_HPP

#include <SFML/Graphics.hpp>

#include "gs2d/scene.hpp"

class MyScene : public gs::Scene {

private:
  sf::CircleShape circle;

public:
  void start();
  void update();
  void draw_entities();
};

#endif
