#include "level_test.hpp"

LevelTest::LevelTest() {}

LevelTest::LevelTest(Character *player, fox::LevelBundle *bundle) :
                     FoxerLevel("assets/levels/level01.json", bundle),
                     player(player) {}

void LevelTest::init(){
  const fox::TiledJsonObj start_pos = get_event("player_start_pos");
  player->set_sprite_position(start_pos.x, start_pos.y);
  bundle->camera.center_at_sprite(player->get_sprite());
}

void LevelTest::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(get_layers(1, 4));
  target.draw(*player);
}
