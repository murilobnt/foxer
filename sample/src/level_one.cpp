#include "level_one.hpp"

LevelOne::LevelOne() {}

LevelOne::LevelOne(gs::MainObject *character, gs::LevelProxy *level_proxy,
                   const std::string &start_position_id, bool fade_in)
    : gs::SampleLevel(character, level_proxy, "assets/levels/level01.json",
                      start_position_id, fade_in) {}

void LevelOne::level_init() {
  exit.exit_load(events.find("level_change")->second, "destination");
  level_two_loader.run(
      new LevelTwo(character, level_proxy, exit.get_destination_id()),
      tex_manager);
}

void LevelOne::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  if (fader.get_fade_state() != gs::NOT_FADING) {
    target.draw(get_layers());
    target.draw(fader);
    target.draw(character->get_sprite());
  } else {
    target.draw(get_layers(1, 4));
    target.draw(*character);
    target.draw(get_layer(5));
  }
}

void LevelOne::on_fade_out() { change_level(loader->get_level()); }

void LevelOne::on_fade_in() {}

void LevelOne::handle_level_events(const float &delta_time) {
  sf::FloatRect char_rect = character->get_sprite_global_bounds();
  char_rect.height -= 22;
  char_rect.top += 15;

  if (exit.collides_with(char_rect)) {
    character->set_movement(sf::Vector2f(0, 0));
    character->animate();
    fader.start_fade_out();
    loader = &level_two_loader;
  }
}
