#include "my_scene.hpp"

void MyScene::start() {
  time_handlers.push_back(character.get_time_handler());

  character = Character(
      tex_manager.load("char_texture", "assets/textures/character.png"));

  l_proxy.change_level(
      new LevelOne(&character, &l_proxy, "player_start_pos", false));

  camera = gs::Camera(sf::Vector2f(544, 416), 0.5);
  camera.center_at_position(character.get_sprite_position());
  app_window->setView(camera.get_view());
}

void MyScene::update() {
  l_proxy.handle_events(get_delta_time());
  camera.center_at_position(character.get_sprite_position());
  app_window->setView(camera.get_view());
}

void MyScene::draw_entities() { app_window->draw(l_proxy); }
