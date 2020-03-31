#include "level_test.hpp"

LevelTest::LevelTest() {}

LevelTest::LevelTest(Character *player, fox::LevelBundle *bundle) :
                     FoxerLevel("assets/levels/level02.json", bundle),
                     player(player) {}

void LevelTest::init(){
  const fox::TiledJsonObj start_pos = get_event("gate0");
  player->set_sprite_position(start_pos.x, start_pos.y);
  bundle->camera.center_at_sprite(player->get_sprite());
}

void LevelTest::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(get_layers(1, 4));
  target.draw(*player);
}

void LevelTest::control_camera(const float &delta_time){
  bundle->camera.move(sf::Vector2f((player->get_sprite_position() -
                      bundle->camera.get_center())) *
                      (delta_time * 5));

  sf::Vector2f camera_size = bundle->camera.get_size();
  sf::Vector2f center = bundle->camera.get_center();
  sf::Vector2f final_position = center;

  const sf::Vector2u tile_size =
  fox::FoxerLevel::get_level_data().get_tile_size();
  const sf::Vector2u level_size =
  fox::FoxerLevel::get_level_data().get_level_size();

  if (center.x - (camera_size.x / 2) < 0)
    final_position.x = camera_size.x / 2;
  if (center.y - (camera_size.y / 2) < 0)
    final_position.y = camera_size.y / 2;
  if (center.x + (camera_size.x / 2) > level_size.x * tile_size.x)
    final_position.x = (level_size.x * tile_size.x) - (camera_size.x / 2);
  if (center.y + (camera_size.y / 2) > level_size.y * tile_size.y)
    final_position.y = (level_size.y * tile_size.y) - (camera_size.y / 2);

  bundle->camera.center_at_position(final_position);
}
