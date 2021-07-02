#include "foxer/logical/foxer_collision_handler.hpp"

namespace fox {

FoxerCollisionHandler::FoxerCollisionHandler
(GameObject *go, const std::unique_ptr<TileGrid> &level_tile_grid) : go(go),
	level_tile_grid(level_tile_grid)
{ }

void FoxerCollisionHandler::handle_collision() {
  if(!level_tile_grid)
	  return;
  sf::Vector2f movement = go->get_movement();

  sf::FloatRect gb = go->getGlobalBounds();
  gb.height -= go->collision_offset_up + go->collision_offset_down;
  gb.width -= go->collision_offset_left + go->collision_offset_right;
  gb.top += go->collision_offset_up;
  gb.left += go->collision_offset_left;

  sf::FloatRect gb_x = gb;
  sf::FloatRect gb_y = gb;

  gb_x.left += movement.x;
  gb_y.top += movement.y;

  std::vector<Unity> unities =
      level_tile_grid->get_unities_in_position(go->getPosition(),
                                              go->getGlobalBounds());

  for (std::vector<Unity>::iterator it = unities.begin(); it != unities.end();
       ++it) {
    Unity unity = *it;

    for (std::vector<Tile>::iterator it2 = unity.tiles.begin();
         it2 != unity.tiles.end(); ++it2) {
      sf::FloatRect tile_rect = (*it2).get_tile_rect();
      if (tile_rect.intersects(gb_x)){
        go->set_movement_x(0);
      }
      if(tile_rect.intersects(gb_y)){
        go->set_movement_y(0);
      }
    }
  }
}

} // namespace fox
