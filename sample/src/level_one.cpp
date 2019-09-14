#include "level_one.hpp"

LevelOne::LevelOne() {}

LevelOne::LevelOne(gs::LevelProxy *level_proxy, gs::MainObject *character,
                   const std::string &start_position_id, gs::Camera *camera,
                   sf::Vector2f *delay, bool fade_in)
    : gs::SampleLevel(level_proxy, character, "assets/levels/level01.json",
                      start_position_id, fade_in) {
  this->camera = camera;
  this->delay = delay;
}

void LevelOne::level_init() {
  exit.exit_load(events.find("level_change")->second, "destination");
  level_two_loader.run(new LevelTwo(level_proxy, character,
                                    exit.get_destination_id(), camera, delay),
                       tex_holder);
  camera->center_at_position(character->get_sprite_position() -
                             ((*delay) * (fading_speed / 5.f)));
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
    *delay =
        sf::Vector2f((character->get_sprite_position() - camera->get_center()) *
                     (delta_time * 5));
    fader.start_fade_out();
    loader = &level_two_loader;
  }
}
