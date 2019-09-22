#include "my_scene.hpp"

void MyScene::start() {
  time_handlers.push_back(character.get_time_handler());
  character = Character(tex_holder.load("assets/textures/character.png"));

  camera = gs::Camera(sf::Vector2f(480, 320));
  bundle = gs::LevelBundle(&l_proxy, &shared_holder, &camera);
  s_bundle = SampleBundle(&character, &delay);

  l_proxy.change_level(
      new LevelOne(&bundle, &s_bundle, "player_start_pos", true, false));
}

void MyScene::update() {
  l_proxy.handle_events(get_delta_time());
  l_proxy.control_camera(get_delta_time());
  app_window->setView(camera.get_view());
}

void MyScene::draw_entities() { app_window->draw(l_proxy); }
