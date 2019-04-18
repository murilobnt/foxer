#include "level_one.hpp"
#include "level_two.hpp"

LevelTwo::LevelTwo() {}

LevelTwo::LevelTwo(Character *character, gs::LevelProxy *level_proxy,
                   const std::string &start_position_id, bool fade_in)
    : gs::TiledLevel("assets/levels/level02.json", false) {
  set_level_proxy(level_proxy);
  this->character = character;
  this->start_position_id = start_position_id;
  this->fade_in = fade_in;
}

void LevelTwo::init() {
  gs::TiledJsonObj m_exit = events.find("level_change")->second;
  destination_id = m_exit.properties["destination"].get<std::string>();
  exit = sf::FloatRect(m_exit.x, m_exit.y, m_exit.width, m_exit.height);

  gs::TiledJsonObj start_pos = get_event(start_position_id);
  character->set_sprite_position(start_pos.x, start_pos.y);
  fader = gs::Fader(
      sf::Vector2f(level_size.x * tile_size.x, level_size.y * tile_size.y));

  level_one_loader.run(new LevelOne(character, level_proxy, destination_id));

  if (fade_in)
    fader.start_fade_in();
}

void LevelTwo::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  if (fader.get_fade_state() != gs::NOT_FADING) {
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

  sf::FloatRect char_rect = character->get_sprite_global_bounds();
  char_rect.height -= 22;
  char_rect.top += 15;

  if (exit.intersects(char_rect)) {
    character->set_movement(sf::Vector2f(0, 0));
    character->animate();
    fader.start_fade_out();
    loader = &level_one_loader;
  }
}

void LevelTwo::handle_fade(const gs::FadeState &fade_state) {
  character->time_trigger();
  switch (fade_state) {
  case gs::FADING_OUT:
    if (fader.fade_out(15))
      change_level(loader->get_level());
    break;
  case gs::FADING_IN:
    fader.fade_in(15);
    break;
  }
}

void LevelTwo::handle_events(const float &delta_time) {
  if (fader.get_fade_state() != gs::NOT_FADING)
    handle_fade(fader.get_fade_state());
  else
    handle_game_events(delta_time);
}
