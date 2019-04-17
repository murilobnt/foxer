#ifndef LEVEL_TWO_HPP
#define LEVEL_TWO_HPP

#include <gs2d/game/level/tiled_level.hpp>
#include <gs2d/other/helpers/fader.hpp>
#include <gs2d/scene/components/object/game_object.hpp>

#include "character.hpp"

class LevelTwo : public gs::TiledLevel {
private:
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  Character *character;
  std::string start_position_id;

  gs::Fader fader;
  bool transition;

  void handle_game_events(const float &delta_time);
  void handle_fade();

public:
  LevelTwo();
  LevelTwo(Character *character, const std::string &start_position_id);
  void init();
  void handle_events(const float &delta_time);
};

#endif
