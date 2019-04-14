#ifndef LEVEL_ONE_HPP
#define LEVEL_ONE_HPP

#include <gs2d/game/level/tiled_level.hpp>
#include <gs2d/scene/components/object/game_object.hpp>

class LevelOne : public gs::TiledLevel {
private:
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  gs::GameObject *character;

public:
  LevelOne();
  LevelOne(const std::string &json_tiled_file, gs::GameObject *character);
  void handle_events();
};

#endif
