#include "level_one.hpp"

LevelOne::LevelOne() {}

LevelOne::LevelOne(Character *player, fox::LevelBundle *bundle,
                     const std::string start_id) :
                     FoxerLevel("assets/levels/level01.json", bundle),
                     player(player),
                     start_id(start_id) {}

void LevelOne::init(){
  const fox::TiledJsonObj start_pos = get_event(start_id);
  const fox::TiledJsonObj level_change = get_event("level_change");

  exit = fox::EventArea(level_change,
  std::make_unique<fox::FoxerExitAreaCH>(&bundle->level_proxy,
  std::make_shared<LevelTwo>(player, bundle, "gate0")));

  player->setPosition(start_pos.x, start_pos.y);
  bundle->textbox->display_text("Hey. This is a demo.\n\nIt took me quite some long time to figure out the proper way to code this textbox.\nBut here it is! Finally complete.");
}

void LevelOne::level_update(const float &delta_time){
  if(!bundle->textbox->is_active()){
    fox::FoxerLevel::level_update(delta_time);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
      bundle->textbox->start();
  }
  else {
    bundle->player_ref->time_trigger();
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
      bundle->textbox->next();
    bundle->textbox->update_text_state();
  }

  exit.verify_collision(player->getGlobalBounds());
}

void LevelOne::draw(sf::RenderTarget &target,
                     sf::RenderStates states) const {
  target.draw(get_layers(1, 3));
  target.draw(*player);
  target.draw(get_layer(4));
  if(bundle->textbox->is_active())
    target.draw(*bundle->textbox);
}
