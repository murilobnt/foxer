#ifndef LEVEL_ONE_HPP
#define LEVEL_ONE_HPP

#include <gs2d/game/level/threaded_level_loader.hpp>
#include <gs2d/game/level/tiled_level.hpp>
#include <gs2d/other/helpers/fader.hpp>

#include "character.hpp"
#include "level_two.hpp"

class LevelOne : public gs::TiledLevel {
private:
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  Character *character;

  sf::FloatRect exit;
  std::string destination_id;
  gs::ThreadedLevelLoader loader;

  gs::Fader fader;
  bool transition;

  void handle_game_events(const float &delta_time);
  void handle_fade();

public:
  LevelOne();
  LevelOne(Character *character, gs::LevelProxy *level_proxy);
  void init();
  void handle_events(const float &delta_time);
};

#endif
