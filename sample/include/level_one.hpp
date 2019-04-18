#ifndef LEVEL_ONE_HPP
#define LEVEL_ONE_HPP

#include <functional>
#include <gs2d/game/level/threaded_level_loader.hpp>
#include <gs2d/game/level/tiled_level.hpp>
#include <gs2d/other/helpers/fader.hpp>

#include "character.hpp"
#include "level_two.hpp"

class LevelOne : public gs::TiledLevel {
private:
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  Character *character;
  std::string start_position_id;

  sf::FloatRect exit;
  std::string destination_id;
  gs::ThreadedLevelLoader level_two_loader;
  gs::ThreadedLevelLoader *loader;

  gs::Fader fader;
  bool fade_in;

  void handle_game_events(const float &delta_time);
  void handle_fade(const gs::FadeState &fade_state);

public:
  LevelOne();
  LevelOne(Character *character, gs::LevelProxy *level_proxy,
           const std::string &start_position_id, bool fade_in = true);
  void init();
  void handle_events(const float &delta_time);
};

#endif
