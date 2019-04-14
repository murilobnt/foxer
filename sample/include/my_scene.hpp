#ifndef MY_SCENE_HPP
#define MY_SCENE_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <gs2d/scene.hpp>

#include "character.hpp"
#include "level_one.hpp"

class MyScene : public gs::Scene {
private:
  sf::Texture char_texture;
  Character character;
  gs::Camera camera;
  sf::Music bgm;

  LevelOne level;

public:
  void start();
  void update();
  void draw_entities();
};

#endif
