#include "level_one.hpp"
#include "level_two.hpp"

LevelTwo::LevelTwo() {}

LevelTwo::LevelTwo(gs::MainObject *character, gs::LevelProxy *level_proxy,
                   const std::string &start_position_id, bool fade_in)
    : gs::SampleLevel(character, level_proxy, "assets/levels/level02.json",
                      start_position_id, fade_in) {}

void LevelTwo::level_init() {
  exit.exit_load(events.find("level_change")->second, "destination");
  level_one_loader.run(
      new LevelOne(character, level_proxy, exit.get_destination_id()),
      tex_manager);
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

void LevelTwo::handle_level_events(const float &delta_time) {
  sf::FloatRect char_rect = character->get_sprite_global_bounds();
  char_rect.height -= 22;
  char_rect.top += 15;

  if (exit.collides_with(char_rect)) {
    character->set_movement(sf::Vector2f(0, 0));
    character->animate();
    fader.start_fade_out();
    loader = &level_one_loader;
  }
}

void LevelTwo::on_fade_out() { change_level(loader->get_level()); }

void LevelTwo::on_fade_in() {}
