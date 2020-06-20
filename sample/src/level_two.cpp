#include "level_one.hpp"
#include "level_two.hpp"

LevelTwo::LevelTwo() {}

LevelTwo::LevelTwo(Character *player, fox::LevelBundle *bundle,
                   const std::string start_id) :
                     FoxerLevel("assets/levels/level02.json", bundle),
                     player(player),
                     start_id(start_id) {}

void LevelTwo::init(){
  const fox::TiledJsonObj start_pos = get_event(start_id);
  const fox::TiledJsonObj level_change = get_event("level_change");

  exit = fox::EventArea(level_change,
  std::make_unique<fox::FoxerExitAreaCH>(&bundle->level_proxy,
  std::make_shared<LevelOne>(player, bundle, "gate0")));

  player->set_sprite_position(start_pos.x, start_pos.y);
}

void LevelTwo::handle_events(const float &delta_time){
  fox::FoxerLevel::handle_events(delta_time);
  exit.verify_collision(player->get_sprite_global_bounds());
}

void LevelTwo::draw(sf::RenderTarget &target,
                     sf::RenderStates states) const {
  target.draw(get_layers(1, 4));
  target.draw(*player);
}
