#ifndef LEVEL_ONE_HPP
#define LEVEL_ONE_HPP

#include <gs2d/game/level/threaded_level_loader.hpp>
#include <gs2d/game/level/tiled_level.hpp>
#include <gs2d/scene/components/object/game_object.hpp>

#include "level_two.hpp"

class LevelOne : public gs::TiledLevel {
private:
  void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  gs::GameObject *character;

  sf::FloatRect exit;
  std::string destination_id;
  gs::ThreadedLevelLoader loader;

public:
  LevelOne();
  LevelOne(gs::GameObject *character, gs::LevelProxy *level_proxy);
  void init();
  void handle_events();
};

#endif
