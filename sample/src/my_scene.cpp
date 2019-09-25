#include "my_scene.hpp"

void MyScene::start() {
  time_handlers.push_back(character.get_time_handler());
  character = Character(tex_holder.load("assets/textures/character.png"));

  camera = gs::Camera(sf::Vector2f(480, 320));

  std::shared_ptr<LevelOne> level_one =
      std::make_shared<LevelOne>("player_start_pos");

  level_one->set_player(&character);
  level_one->set_delay(&delay);
  level_one->set_level_bundle(&level_bundle);
  level_one->load();

  l_proxy.change_level(level_one);
}

void MyScene::update() {
  l_proxy.handle_events(get_delta_time());
  l_proxy.control_camera(get_delta_time());
  app_window->setView(camera.get_view());
}

void MyScene::draw_entities() { app_window->draw(l_proxy); }
