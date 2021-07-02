#include "level_test.hpp"

LevelTest::LevelTest() {}

LevelTest::LevelTest(Character *player, fox::LevelBundle *bundle, const std::string start_id) :
                     FoxerLevel("assets/levels/level.json", bundle),
                     player(player),
                     start_id(start_id){}

void LevelTest::init(){
  const fox::TiledJsonObj start_pos = get_event(start_id);

  player->setPosition(start_pos.x, start_pos.y);
}

void LevelTest::level_update(const float &delta_time){
	fox::FoxerLevel::level_update(delta_time);
}

void LevelTest::draw(sf::RenderTarget &target,
                     sf::RenderStates states) const {
  //target.draw(get_layers(1, 3));
  //target.draw(get_layer(1));
  target.draw(*player);
}
