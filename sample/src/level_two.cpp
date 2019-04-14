#include "level_two.hpp"

LevelTwo::LevelTwo() {}

LevelTwo::LevelTwo(gs::GameObject *character,
                   const std::string &start_position_id)
    : gs::TiledLevel("assets/levels/level02.json") {
  this->character = character;
  gs::TiledJsonObj start_pos = get_event(start_position_id);
  character->set_sprite_position(start_pos.x, start_pos.y);
}

void LevelTwo::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(get_layers(1, 2));
  target.draw(character->get_sprite());
  target.draw(get_layer(3));
}

void LevelTwo::handle_events() { collision_map.verify_collision(*character); }
