#ifndef LEVEL_TWO_HPP
#define LEVEL_TWO_HPP

#include <gs2d/game/level/tiled_level.hpp>
#include <gs2d/scene/components/object/game_object.hpp>

#include "character.hpp"

class LevelTwo : public gs::TiledLevel {
private:
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  Character *character;
  std::string start_position_id;

  sf::RectangleShape fader;
  bool transition;
  int alpha;

  void control_character(const float &delta_time);

public:
  LevelTwo();
  LevelTwo(Character *character, const std::string &start_position_id);
  void init();
  void handle_events(const float &delta_time);
};

#endif
