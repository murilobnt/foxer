#ifndef MY_SCENE_HPP
#define MY_SCENE_HPP

#include <SFML/Graphics.hpp>
#include <gs2d/game/level/level_bundle.hpp>
#include <gs2d/game/level/level_proxy.hpp>
#include <gs2d/scene.hpp>

#include "character.hpp"
#include "level_one.hpp"
#include "sample_bundle.hpp"

class MyScene : public gs::Scene {
private:
  SampleBundle s_bundle;

  Character character;
  sf::Vector2f delay;

public:
  void start();
  void update();
  void draw_entities();
};

#endif
