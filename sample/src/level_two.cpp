#include "level_one.hpp"
#include "level_two.hpp"

LevelTwo::LevelTwo() {}

LevelTwo::LevelTwo(gs::LevelProxy *level_proxy, gs::MainObject *character,
                   const std::string &start_position_id, gs::Camera *camera,
                   sf::Vector2f *delay, bool fade_in)
    : gs::SampleLevel(level_proxy, character, camera,
                      "assets/levels/level03.json", start_position_id, fade_in),
      CommonLevel(delay) {
  this->camera = camera;
}

void LevelTwo::level_init() {
  exit.exit_load(events.find("level_change")->second, "destination");
  level_one_loader.run(new LevelOne(level_proxy, character,
                                    exit.get_destination_id(), camera, delay),
                       tex_holder);
  initialise_camera(character, camera, fading_speed);
}

void LevelTwo::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  if (fader.get_fade_state() != gs::NOT_FADING) {
    target.draw(get_layers());
    target.draw(fader);
    target.draw(*character);
  } else {
    target.draw(get_layers(1, 4));
    target.draw(*character);
  }
}

void LevelTwo::handle_level_events(const float &delta_time) {
  sf::FloatRect char_rect = character->get_sprite_global_bounds();
  char_rect.height -= 22;
  char_rect.top += 15;

  if (exit.collides_with(char_rect)) {
    stop_character(character, camera, delta_time);
    fader.start_fade_out();
    loader = &level_one_loader;
  }
}

void LevelTwo::on_fade_out() { change_level(loader->get_level()); }

void LevelTwo::on_fade_in() {}

void LevelTwo::control_camera(const float &delta_time) {
  camera->move(
      sf::Vector2f((character->get_sprite_position() - camera->get_center())) *
      (delta_time * 5));

  adjust_camera(camera, level_size, tile_size);
}
