#include "my_scene.hpp"

void MyScene::start() {
  time_handlers.push_back(character.get_time_handler());

  gs::TextureLoader::set_texture_from_file(
      char_texture, std::string("assets/chara.png"), 286, 232);
  character = Character(char_texture);

  gs::TiledLevel first_level =
      gs::TiledLevel(std::vector<std::string>{"assets/tileset02.png",
                                              "assets/steampunkish-tilec.png"},
                     "assets/level01.json");

  camera = gs::Camera(sf::Vector2f(1366, 768), 0.5);

  level_manager =
      LevelManager(&character, first_level,
                   std::shared_ptr<LevelHandler>(
                       new LevelOneHandler(first_level.get_events())));

  bgm.openFromFile("assets/almost-new-by-kevin-macleod.wav");
  bgm.play();
}

void MyScene::update() {
  character.control_entity(get_delta_time());
  level_manager.verify_collision();
  character.time_trigger();
  character.move();
  camera.center_at_sprite(character.get_sprite());
  app_window->setView(camera.get_view());
}

void MyScene::draw_entities() {
  app_window->draw(level_manager.get_level().get_lower_layers());
  app_window->draw(character.get_sprite());
  app_window->draw(level_manager.get_level().get_overlay_layers());
}
