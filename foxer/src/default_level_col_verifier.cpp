#include "foxer/other/geared_up/default_level_col_verifier.hpp"

namespace fox {

const CollisionOn
DefaultLevelColVerifier::verify_collision(const GameObject &go,
                 const TileGrid &level_tile_grid) const {

  CollisionOn c_on;
  sf::Vector2f movement = go.get_movement();
  sf::FloatRect gb_x = go.get_sprite_global_bounds();
  sf::FloatRect gb_y = go.get_sprite_global_bounds();

  gb_x.left += movement.x;
  gb_y.top += movement.y;

  std::vector<Unity> unities =
      level_tile_grid.get_unities_in_position(go.get_sprite_position(),
                                              go.get_sprite_global_bounds());

  for (std::vector<Unity>::iterator it = unities.begin(); it != unities.end();
       ++it) {
    Unity unity = *it;

    for (std::vector<Tile>::iterator it2 = unity.tiles.begin();
         it2 != unity.tiles.end(); ++it2) {
      sf::FloatRect tile_rect = (*it2).get_tile_rect();
      if (tile_rect.intersects(gb_x))
        c_on.x = true;
      if(tile_rect.intersects(gb_y))
        c_on.y = true;
    }
  }

  return c_on;
}

} // namespace fox
