#include "menu_example.hpp"
#include "test_scene.hpp"

TestScene::~TestScene() {
  std::cout << "My destructor have been called. Yay!" << std::endl;
}

void TestScene::start() {
  camera = gs::Camera(sf::Vector2f(800, 600));

  tiled_level.load("assets/images/test_tileset.png",
                   "assets/levels/level01.json");
  tile_layers = tiled_level.get_tile_layers();
  collision_map = tiled_level.get_collision_map();

  time_handlers.push_back(&character.get_animation_time_handler());

  gs::TextureLoader::set_texture_from_file(
      char_texture, "assets/images/link_edit4040.png", 400, 320);
  character = Character(char_texture, sf::Vector2i(0, 0), sf::Vector2i(40, 40),
                        sf::Vector2i(0, 400), sf::Vector2i(160, 280), 20);

  character.collision_offset_up = 16;
  character.collision_offset_down = 38;
  character.collision_offset_left = 9;
  character.collision_offset_right = 9;

  gs::TiledJsonObj player_start_pos = tiled_level.get_event("player_start_pos");
  character.set_sprite_position(
      sf::Vector2f(player_start_pos.x, player_start_pos.y));
}

void TestScene::update() {
  camera.center_at_sprite(character.get_sprite());
  app_window->setView(camera.get_view());

  timed_events();

  character.control_entity(get_delta_time());
  collision_map.verify_collision(character);
  character.move();
  character.nullfy_movement();
}

void TestScene::handle_event(sf::Event &event) {
  switch (event.type) {
  case sf::Event::Closed:
    app_window->close();
    break;
  case sf::Event::KeyReleased:
    switch (event.key.code) {
    case sf::Keyboard::P:
      change_scene(new SecondScene());
      break;
    case sf::Keyboard::Escape:
      change_scene(new MenuExample());
      break;
    }
  }
}

void TestScene::draw_entities() {
  for (int i = 0; i < tile_layers.size(); ++i) {
    app_window->draw(tile_layers.at(i));
  }
  app_window->draw(character.get_sprite());
}

void TestScene::timed_events() {
  while (character.get_animation_time_handler().time_to_update())
    character.animate();
}

void TestScene::on_exit() {
  sf::Vector2u window_size = app_window->getSize();
  camera.center_at_position(sf::Vector2f(window_size.x / 2, window_size.y / 2));
  app_window->setView(camera.get_view());
}
