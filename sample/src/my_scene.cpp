#include "my_scene.hpp"

void MyScene::start() {
  gs::TextureLoader::set_texture_from_file(
      char_texture, std::string("assets/chara.png"), 286, 232);
  time_handlers.push_back(character.get_time_handler());
  m_level.load(std::vector<std::string>{"assets/tileset02.png",
                                        "assets/steampunkish-tilec.png"},
               "assets/level01.json");
  gs::TiledJsonObj start_pos = m_level.get_event("player_start_pos");
  character = Character(char_texture, sf::Vector2f(start_pos.x, start_pos.y));
  camera = gs::Camera(sf::Vector2f(1366, 768), 0.5);
  col_map = m_level.get_collision_map();
  bgm.openFromFile("assets/almost-new-by-kevin-macleod.wav");
  bgm.play();
}

void MyScene::update() {
  character.control_entity(get_delta_time());
  col_map.verify_collision(character);
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
