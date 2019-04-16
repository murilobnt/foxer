#include "level_two.hpp"

LevelTwo::LevelTwo() {}

LevelTwo::LevelTwo(Character *character, const std::string &start_position_id)
    : gs::TiledLevel("assets/levels/level02.json", false), alpha(255),
      transition(true) {
  this->character = character;
  this->start_position_id = start_position_id;
}

void LevelTwo::init() {
  gs::TiledJsonObj start_pos = get_event(start_position_id);
  character->set_sprite_position(start_pos.x, start_pos.y);
  fader = sf::RectangleShape(
      sf::Vector2f(level_size.x * tile_size.x, level_size.y * tile_size.y));
  fader.setFillColor(sf::Color(0, 0, 0, alpha));
}

void LevelTwo::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  if (transition) {
    target.draw(get_layers(1, 2));
    target.draw(get_layer(3));
    target.draw(fader);
    target.draw(character->get_sprite());
  } else {
    target.draw(get_layers(1, 2));
    target.draw(character->get_sprite());
    target.draw(get_layer(3));
  }
}

void LevelTwo::control_character(const float &delta_time) {
  character->control_entity(delta_time);
  collision_map.verify_collision(*character);
  character->time_trigger();
  character->move();
}

void LevelTwo::handle_events(const float &delta_time) {
  if (transition) {
    character->time_trigger();
    alpha = (alpha - 15 < 0 ? 0 : alpha - 15);
    fader.setFillColor(sf::Color(0, 0, 0, alpha));
    if (alpha == 0)
      transition = false;
  } else {
    control_character(delta_time);
  }
}
