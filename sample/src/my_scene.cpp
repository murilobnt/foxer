#include "my_scene.hpp"

void MyScene::start() {
  gs::TextureLoader::set_texture_from_file(
      char_texture, std::string("assets/chara.png"), 286, 232);
  character = Character(char_texture, sf::Vector2f(100, 100));
  time_handlers.push_back(character.get_time_handler());
  m_level.load(std::vector<std::string>{"assets/tileset02.png",
                                        "assets/steampunkish-tilec.png"},
               "assets/level01.json");
  camera = gs::Camera(sf::Vector2f(800, 600));
}

void MyScene::update() {
  character.control_entity(get_delta_time());
  character.time_trigger();
  character.move();
  camera.center_at_sprite(character.get_sprite());
  app_window->setView(camera.get_view());
  // we'll do nothing over here
}

void MyScene::draw_entities() {
  app_window->draw(m_level.get_lower_layers());
  app_window->draw(character.get_sprite());
  app_window->draw(m_level.get_overlay_layers());
}
