#ifndef MY_SCENE_HPP
#define MY_SCENE_HPP

#include <SFML/Graphics.hpp>

#include "character.hpp"
#include "gs2d/game/level/tiled_level.hpp"
#include "gs2d/scene.hpp"

class MyScene : public gs::Scene {

private:
  gs::TiledLevel m_level;
  sf::Texture char_texture;
  gs::Camera camera;
  Character character;

public:
  void start();
  void update();
  void draw_entities();
};

#endif
