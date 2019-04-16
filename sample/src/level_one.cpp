#include "level_one.hpp"

LevelOne::LevelOne() {}

LevelOne::LevelOne(Character *character, gs::LevelProxy *level_proxy)
    : gs::TiledLevel("assets/levels/level01.json"),
      fader(
          sf::Vector2f(level_size.x * tile_size.x, level_size.y * tile_size.y)),
      alpha(0), transition(false) {
  set_level_proxy(level_proxy);
  this->character = character;

  gs::TiledJsonObj m_exit = events.find("level_change")->second;
  destination_id = m_exit.properties["destination"].get<std::string>();
  exit = sf::FloatRect(m_exit.x, m_exit.y, m_exit.width, m_exit.height);

  fader.setFillColor(sf::Color(0, 0, 0, alpha));
}

void LevelOne::init() {
  gs::TiledJsonObj start_pos = get_event("player_start_pos");
  character->set_sprite_position(start_pos.x, start_pos.y);

  loader.run(new LevelTwo(character, destination_id));
}

void LevelOne::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  if (transition) {
    target.draw(get_layers(1, 2));
    target.draw(get_layers(3, 4));
    target.draw(fader);
    target.draw(character->get_sprite());
  } else {
    target.draw(get_layers(1, 2));
    target.draw(character->get_sprite());
    target.draw(get_layers(3, 4));
  }
}

void LevelOne::control_character(const float &delta_time) {
  character->control_entity(delta_time);
  collision_map.verify_collision(*character);
  character->time_trigger();
  character->move();
}

void LevelOne::handle_events(const float &delta_time) {
  if (transition) {
    character->time_trigger();
    alpha = (alpha + 15 > 255 ? 255 : alpha + 15);
    fader.setFillColor(sf::Color(0, 0, 0, alpha));
    if (alpha == 255)
      change_level(loader.get_level());
  } else {
    control_character(delta_time);
    if (exit.intersects(character->get_sprite_global_bounds())) {
      character->set_movement(sf::Vector2f(0, 0));
      character->animate();
      transition = true;
    }
  }
}
