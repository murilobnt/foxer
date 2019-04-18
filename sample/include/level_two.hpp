#ifndef LEVEL_TWO_HPP
#define LEVEL_TWO_HPP

#include <gs2d/game/level/tiled_level.hpp>
#include <gs2d/other/helpers/fader.hpp>
#include <gs2d/scene/components/object/game_object.hpp>

#include "character.hpp"

class LevelOne;

class LevelTwo : public gs::TiledLevel {
private:
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  Character *character;
  std::string start_position_id;

  sf::FloatRect exit;
  std::string destination_id;
  gs::ThreadedLevelLoader level_one_loader;
  gs::ThreadedLevelLoader *loader;

  gs::Fader fader;
  bool fade_in;

  void handle_game_events(const float &delta_time);
  void handle_fade(const gs::FadeState &fade_state);

public:
  LevelTwo();
  LevelTwo(Character *character, gs::LevelProxy *level_proxy,
           const std::string &start_position_id, bool fade_in = true);
  void init();
  void handle_events(const float &delta_time);
};

#endif
