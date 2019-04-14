#include "my_scene.hpp"

void MyScene::start() {
  time_handlers.push_back(character.get_time_handler());

  gs::TextureLoader::set_texture_from_file(
      char_texture, std::string("assets/textures/chara.png"), 286, 232);
  character = Character(char_texture);

  l_proxy.change_level(new LevelOne(&character, &l_proxy));

  camera = gs::Camera(sf::Vector2f(1366, 768), 0.5);

  bgm.openFromFile("assets/musics/almost-new-by-kevin-macleod.wav");
  bgm.play();
}

void MyScene::update() {
  character.control_entity(get_delta_time());
  l_proxy.handle_events();
  character.time_trigger();
  character.move();
  camera.center_at_sprite(character.get_sprite());
  app_window->setView(camera.get_view());
}

void MyScene::draw_entities() { app_window->draw(l_proxy); }
