#include "level_two.hpp"

LevelTwo::LevelTwo() {}

LevelTwo::LevelTwo(Character *character, const std::string &start_position_id)
    : gs::TiledLevel("assets/levels/level02.json", false), transition(true) {
  this->character = character;
  this->start_position_id = start_position_id;
}

void LevelTwo::init() {
  gs::TiledJsonObj start_pos = get_event(start_position_id);
  character->set_sprite_position(start_pos.x, start_pos.y);
  fader = gs::Fader(
      sf::Vector2f(level_size.x * tile_size.x, level_size.y * tile_size.y));
}

void LevelTwo::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  if (transition) {
    target.draw(get_layers());
    target.draw(fader);
    target.draw(character->get_sprite());
  } else {
    target.draw(get_layers(1, 3));
    target.draw(*character);
    target.draw(get_layer(4));
  }
}

void LevelTwo::handle_game_events(const float &delta_time) {
  character->control_entity(delta_time);
  collision_map.verify_collision(*character);
  character->time_trigger();
  character->move();
}

void LevelTwo::handle_fade() {
  character->time_trigger();
  if (fader.fade_in(15))
    transition = false;
}

void LevelTwo::handle_events(const float &delta_time) {
  if (transition)
    handle_fade();
  else
    handle_game_events(delta_time);
}
