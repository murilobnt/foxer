#include "level_handler.hpp"
#include "level_manager.hpp"

LevelManager::LevelManager() {}

LevelManager::LevelManager(gs::GameObject *obj, gs::TiledLevel level,
                           std::shared_ptr<LevelHandler> level_handler) {
  this->obj = obj;
  this->level = level;
  this->level_handler = level_handler;
  init("player_start_pos");
}

void LevelManager::init(std::string player_start_pos_id) {
  gs::TiledJsonObj start_pos = level.get_event(player_start_pos_id);
  obj->set_sprite_position(sf::Vector2f(start_pos.x, start_pos.y));
  col_map = level.get_collision_map();
}

void LevelManager::verify_collision() {
  col_map.verify_collision(*obj);
  level_handler->handle_event_collision(this, obj->get_sprite_global_bounds());
}

gs::TiledLevel &LevelManager::get_level() { return level; }

void LevelManager::change_level(gs::TiledLevel n_level,
                                std::shared_ptr<LevelHandler> n_handler,
                                std::string player_start_pos_id) {
  level = n_level;
  level_handler = n_handler;
  init(player_start_pos_id);
}
