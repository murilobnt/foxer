#include "level_one.hpp"

LevelOne::LevelOne() {}

LevelOne::LevelOne(const std::string &json_tiled_file,
                   gs::GameObject *character)
    : gs::TiledLevel(json_tiled_file) {
  this->character = character;
  character->set_sprite_position(110, 200);
}

void LevelOne::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(get_layers(1, 2));
  target.draw(character->get_sprite());
  target.draw(get_layers(3, 4));
}

void LevelOne::handle_events() { collision_map.verify_collision(*character); }
