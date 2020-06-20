#include "my_scene.hpp"

MyScene::MyScene() : delta_time(1.f/60.f) {}

void MyScene::start() {
  physics_rate = fox::TimeHandler(sf::seconds(delta_time));
  time_handlers.push_back(character.get_time_handler());
  time_handlers.push_back(&physics_rate);

  character = Character(ltex_repo.load("assets/textures/character.png"));
  sf::Vector2u window_size = fox::Scene::app_window->getSize();
  bundle.camera = fox::Camera(sf::Vector2f(window_size.x/2, window_size.y/2));
  bundle.stex_repo = &stex_repo;
  bundle.player_ref = &character;

  std::shared_ptr<LevelTest> level_one =
      std::make_shared<LevelTest>(&character, &bundle);

  level_one->load();
  bundle.level_proxy.change_level(level_one);
}

void MyScene::update() {
  while(physics_rate.time_to_update()){
    bundle.level_proxy.handle_events(delta_time);
    bundle.level_proxy.control_camera(delta_time);
  }
}

void MyScene::draw_entities() {
  app_window->setView(bundle.camera.get_view());
  app_window->draw(bundle.level_proxy);
}
