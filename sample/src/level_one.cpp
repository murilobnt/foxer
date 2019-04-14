#include "level_one.hpp"

LevelOne::LevelOne() {}

LevelOne::LevelOne(gs::GameObject *character, gs::LevelProxy *level_proxy)
    : gs::TiledLevel("assets/levels/level01.json") {
  set_level_proxy(level_proxy);
  this->character = character;
  gs::TiledJsonObj start_pos = get_event("player_start_pos");
  character->set_sprite_position(start_pos.x, start_pos.y);

  gs::TiledJsonObj m_exit = events.find("level_change")->second;
  destination_id = m_exit.properties["destination"].get<std::string>();
  exit = sf::FloatRect(m_exit.x, m_exit.y, m_exit.width, m_exit.height);
}

void LevelOne::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(get_layers(1, 2));
  target.draw(character->get_sprite());
  target.draw(get_layers(3, 4));
}

void LevelOne::handle_events() {
  collision_map.verify_collision(*character);
  if (exit.intersects(character->get_sprite_global_bounds())) {
    change_level(new LevelTwo(character, destination_id));
  }
}
