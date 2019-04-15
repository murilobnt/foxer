#ifndef LEVEL_TWO_HPP
#define LEVEL_TWO_HPP

#include <gs2d/game/level/tiled_level.hpp>
#include <gs2d/scene/components/object/game_object.hpp>

class LevelTwo : public gs::TiledLevel {
private:
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  gs::GameObject *character;
  std::string start_position_id;

public:
  LevelTwo();
  LevelTwo(gs::GameObject *character, const std::string &start_position_id);
  void init();
  void handle_events();
};

#endif
