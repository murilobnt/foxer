#include "my_scene.hpp"

void MyScene::start() {
  time_handlers.push_back(character.get_time_handler());
  character = Character(ltex_repo.load("assets/textures/character.png"));
  bundle.camera = fox::Camera(sf::Vector2f(480, 320));
  bundle.stex_repo = &stex_repo;
  bundle.player_ref = &character;

  std::shared_ptr<LevelTest> level_one =
      std::make_shared<LevelTest>(&character, &bundle);

  level_one->load();
  bundle.level_proxy.change_level(level_one);
}

void MyScene::update() {
  bundle.level_proxy.handle_events(get_delta_time());
  bundle.level_proxy.control_camera(get_delta_time());
  app_window->setView(bundle.camera.get_view());
}

void MyScene::draw_entities() { app_window->draw(bundle.level_proxy); }
