#ifndef LEVEL_MANAGER_HPP
#define LEVEL_MANAGER_HPP

#include <gs2d/game/level/tiled_level.hpp>
#include <gs2d/scene/components/camera/camera.hpp>
#include <gs2d/scene/components/object/game_object.hpp>

class LevelHandler;

class LevelManager {
private:
  gs::TiledLevel level;
  gs::CollisionMap col_map;
  std::shared_ptr<LevelHandler> level_handler;

  gs::GameObject *obj;

public:
  LevelManager();
  LevelManager(gs::GameObject *obj, gs::TiledLevel level,
               std::shared_ptr<LevelHandler> level_handler);
  void verify_collision();
  void init(std::string player_start_pos_id);
  gs::TiledLevel &get_level();
  void change_level(gs::TiledLevel n_level,
                    std::shared_ptr<LevelHandler> n_handler,
                    std::string player_start_pos_id);
};

#endif
