#include "my_scene.hpp"

void MyScene::start() {
  time_handlers.push_back(character.get_time_handler());
  character = Character(tex_holder.load("assets/textures/character.png"));

  camera = gs::Camera(sf::Vector2f(480, 320));

  l_proxy.change_level(new LevelOne(&shared_holder, &l_proxy, &character,
                                    "player_start_pos", &camera, &delay, true,
                                    false));

  camera.center_at_position(character.get_sprite_position());
  app_window->setView(camera.get_view());
}

void MyScene::update() {
  l_proxy.handle_events(get_delta_time());
  l_proxy.control_camera(get_delta_time());
  app_window->setView(camera.get_view());
}

void MyScene::draw_entities() { app_window->draw(l_proxy); }
