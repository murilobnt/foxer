#ifndef MY_SCENE_HPP
#define MY_SCENE_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "character.hpp"
#include "gs2d/game/level/tiled_level.hpp"
#include "gs2d/scene.hpp"
#include "level_manager.hpp"
#include "level_one_handler.hpp"

class MyScene : public gs::Scene {
private:
  sf::Texture char_texture;
  Character character;
  LevelManager level_manager;
  gs::Camera camera;
  sf::Music bgm;

public:
  void start();
  void update();
  void draw_entities();
};

#endif
