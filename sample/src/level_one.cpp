#include "level_one.hpp"

LevelOne::LevelOne() {}

LevelOne::LevelOne(Character *character, gs::LevelProxy *level_proxy)
    : gs::TiledLevel("assets/levels/level01.json"),
      fader(sf::Vector2f(level_size.x * tile_size.x,
                         level_size.y * tile_size.y)) {
  set_level_proxy(level_proxy);
  this->character = character;

  gs::TiledJsonObj m_exit = events.find("level_change")->second;
  destination_id = m_exit.properties["destination"].get<std::string>();
  exit = sf::FloatRect(m_exit.x, m_exit.y, m_exit.width, m_exit.height);
}

void LevelOne::init() {
  gs::TiledJsonObj start_pos = get_event("player_start_pos");
  character->set_sprite_position(start_pos.x, start_pos.y);

  loader.run(new LevelTwo(character, destination_id));
}

void LevelOne::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  if (fader.get_in_fade()) {
    target.draw(get_layers());
    target.draw(fader);
    target.draw(character->get_sprite());
  } else {
    target.draw(get_layers(1, 4));
    target.draw(*character);
    target.draw(get_layer(5));
  }
}

void LevelOne::handle_game_events(const float &delta_time) {
  character->control_entity(delta_time);
  collision_map.verify_collision(*character);
  character->time_trigger();
  character->move();

  if (exit.intersects(character->get_sprite_global_bounds())) {
    character->set_movement(sf::Vector2f(0, 0));
    character->animate();
    transition = true;
  }
}

void LevelOne::handle_fade() {
  character->time_trigger();
  if (fader.fade_out(15))
    change_level(loader.get_level());
}

void LevelOne::handle_events(const float &delta_time) {
  if (transition)
    handle_fade();
  else
    handle_game_events(delta_time);
}
