#include "level_test.hpp"

LevelTest::LevelTest() {}

LevelTest::LevelTest(Character *player, fox::LevelBundle *bundle,
                     const std::string start_id) :
                     FoxerLevel("assets/levels/level01.json", bundle),
                     player(player),
                     start_id(start_id) {}

void LevelTest::init(){
  const fox::TiledJsonObj start_pos = get_event(start_id);
  const fox::TiledJsonObj level_change = get_event("level_change");

  exit = fox::EventArea(level_change,
  std::make_unique<fox::FoxerExitAreaCH>(&bundle->level_proxy,
  std::make_shared<LevelTwo>(player, bundle, "gate0")));

  player->set_sprite_position(start_pos.x, start_pos.y);
}

void LevelTest::handle_events(const float &delta_time){
  fox::FoxerLevel::handle_events(delta_time);
  exit.verify_collision(player->get_sprite_global_bounds());
}

void LevelTest::draw(sf::RenderTarget &target,
                     sf::RenderStates states) const {
  target.draw(get_layers(1, 3));
  target.draw(*player);
  target.draw(get_layer(4));
}
